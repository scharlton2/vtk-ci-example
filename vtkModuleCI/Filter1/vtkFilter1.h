/**
 * @class   vtkFilter1
 * @brief   Dummy filter
 */

#ifndef vtkFilter1_h
#define vtkFilter1_h

#include "vtkPolyDataAlgorithm.h"

#include "vtkFilter1Module.h" // For export macro

class VTKFILTER1_EXPORT vtkFilter1: public vtkPolyDataAlgorithm
{
public:
  static vtkFilter1* New();
  vtkTypeMacro(vtkFilter1, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

protected:
  vtkFilter1()           = default;
  ~vtkFilter1() override = default;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

private:
  vtkFilter1(const vtkFilter1&) = delete;
  void operator=(const vtkFilter1&) = delete;
};

#endif
