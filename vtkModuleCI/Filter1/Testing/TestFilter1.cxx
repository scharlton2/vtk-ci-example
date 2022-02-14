#include <iostream>

#include "vtkNew.h"
#include "vtkTestUtilities.h"
#include "vtkXMLPolyDataReader.h"
#include "vtkXMLPolyDataWriter.h"

#include "vtkFilter1.h"

int TestFilter1(int, char* argv[])
{
  vtkNew<vtkXMLPolyDataReader> reader;
  std::string cfname(argv[1]);
  cfname += "/dragon.vtp";
  reader->SetFileName(cfname.c_str());

  vtkNew<vtkFilter1> f1;
  f1->SetInputConnection(reader->GetOutputPort());

  vtkNew<vtkXMLPolyDataWriter> writer;
  writer->SetInputConnection(f1->GetOutputPort());
  writer->SetFileName("filter1.vtp");
  writer->Update();
  writer->Write();

  return 0;
}
