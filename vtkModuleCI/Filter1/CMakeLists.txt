set(vtkfilter1_sources
  vtkFilter1.cxx
)
set(vtkfilter1_headers
  vtkFilter1.h
)
vtk_module_add_module(vtkFilter1
  SOURCES ${vtkfilter1_sources}
  HEADERS ${vtkfilter1_headers}
)
