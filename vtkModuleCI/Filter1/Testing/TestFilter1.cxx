#include <iostream>

#include "vtkActor.h"
#include "vtkImageDifference.h"
#include "vtkNew.h"
#include "vtkPNGReader.h"
#include "vtkPolyDataMapper.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTestUtilities.h"
#include "vtkWindowToImageFilter.h"
#include "vtkXMLPolyDataReader.h"

#include "vtkFilter1.h"

int TestFilter1(int argc, char* argv[])
{
  std::string filename = std::string(argv[1]) + "/dragon.vtp";
  vtkNew<vtkXMLPolyDataReader> reader;
  reader->SetFileName(filename.c_str());

  vtkNew<vtkFilter1> f1;
  f1->SetInputConnection(reader->GetOutputPort());

  // Create a mapper.
  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(f1->GetOutputPort());
  mapper->ScalarVisibilityOn();

  // Create the actor.
  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);

  // Basic visualisation.
  vtkNew<vtkRenderWindow> renWin;
  vtkNew<vtkRenderer> ren;
  renWin->AddRenderer(ren);
  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(renWin);

  ren->AddActor(actor);
  ren->SetBackground(0, 0, 0);
  renWin->SetSize(300, 300);
  renWin->Render();

  // Compare with baseline image
  vtkNew<vtkWindowToImageFilter> rtW2if;
  rtW2if->SetInput(renWin);
  rtW2if->SetInputBufferTypeToRGB();

  std::string baseline = std::string(argv[1]) + "/dragon.png";
  vtkNew<vtkPNGReader> pngReader;
  pngReader->SetFileName(baseline.c_str());

  int threshold = 50;
  vtkNew<vtkImageDifference> diff;
  diff->SetThreshold(0);
  diff->SetInputConnection(rtW2if->GetOutputPort());
  diff->SetImageConnection(pngReader->GetOutputPort());
  diff->UpdateInformation();
  double error = diff->GetThresholdedError();
  if (error <= threshold)
  {
    diff->Update();
    error = diff->GetThresholdedError();
  }
  if (error > threshold)
  {
    std::cerr << "Diff error " << error << " is superiod to threshold " << threshold << std::endl;
    return 1;
  }
  return 0;
}
