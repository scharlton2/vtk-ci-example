if (TARGET VTK::vtkpython)
  # execute
  add_test(NAME "execute_Filter1"
    COMMAND
      "$<TARGET_FILE:VTK::vtkpython>"
      "${CMAKE_CURRENT_LIST_DIR}/execute_Filter1.py")
  set_property(TEST "execute_Filter1" APPEND
    PROPERTY
      ENVIRONMENT "PYTHONPATH=${CMAKE_BINARY_DIR}/${python_destination}")
  if (WIN32)
    set(test_path "$ENV{PATH};${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
    string(REPLACE ";" "\;" test_path "${test_path}")
    set_property(TEST "execute_Filter1" APPEND
      PROPERTY
        ENVIRONMENT "PATH=${test_path}")
  endif ()
endif ()

vtk_add_test_cxx(vtkFilter1Test no_data_tests
  NO_DATA NO_VALID NO_OUTPUT
  TestFilter1.cxx
  ${PROJECT_SOURCE_DIR}/Data
)
vtk_test_cxx_executable(vtkFilter1Test no_data_tests)
