from vtk import vtkSphereSource
from vtkModuleCI import vtkFilter1

pd = vtkSphereSource()

filter = vtkFilter1.vtkFilter1()
filter.SetInputConnection(pd.GetOutputPort())
filter.Update()
