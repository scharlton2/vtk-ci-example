cmake_minimum_required(VERSION 3.8)
project (vtkModuleCI)

## Config

include(GNUInstallDirs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

option(BUILD_SHARED_LIBS "Build shared library" ON)

include(CTest)

## Deps

find_package(VTK
  COMPONENTS
    CommonCore
    CommonDataModel
    CommonExecutionModel
    FiltersCore
    Python
  OPTIONAL_COMPONENTS
    CommonSystem
    IOXML
    TestingCore)

## VTK Module

vtk_module_find_modules(vtkmoduleci_module_files "${CMAKE_CURRENT_SOURCE_DIR}/vtkModuleCI")

vtk_module_scan(
  MODULE_FILES     ${vtkmoduleci_module_files}
  PROVIDES_MODULES vtkmoduleci_provided_modules
  WANT_BY_DEFAULT  ON
  ENABLE_TESTS     ON)

vtk_module_python_default_destination(python_destination)

vtk_module_build(
  MODULES         ${vtkmoduleci_provided_modules}
  INSTALL_EXPORT  vtkModuleCI
  INSTALL_HEADERS ON
  CMAKE_DESTINATION   "${CMAKE_INSTALL_LIBDIR}/cmake/vtkModuleCI"
  HEADERS_DESTINATION "include")


## Install

set(vtkModuleCIExport ${vtkmoduleci_provided_modules})
export(
  TARGETS   ${vtkModuleCIExport}
  NAMESPACE VTK::
  FILE "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/vtkModuleCI/vtkModuleCI-targets.cmake")
install(
  EXPORT      vtkModuleCI
  NAMESPACE   VTK::
  FILE        vtkModuleCI-targets.cmake
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vtkModuleCI")


## Python wrapping

option(BUILD_PYTHON_WRAPPERS "Build python wrapping" ON)

if(BUILD_PYTHON_WRAPPERS)

  vtk_module_wrap_python(
    MODULES         ${vtkmoduleci_provided_modules}
    WRAPPED_MODULES vtkmoduleci_wrapped_modules
    TARGET          VTKCI::Python
    INSTALL_EXPORT  vtkModuleCIPython
    PYTHON_PACKAGE  "vtkModuleCI"
    MODULE_DESTINATION  "${python_destination}"
    CMAKE_DESTINATION   "${CMAKE_INSTALL_LIBDIR}/cmake/vtkModuleCIPython"
    LIBRARY_DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    INSTALL_HEADERS ON
    BUILD_STATIC    OFF)

  # Generate __init__.py
  set(python_modules)
  foreach(module ${vtkmoduleci_wrapped_modules})
    list(APPEND python_modules "'${module}'")
  endforeach()

  set(InitContent "__all__ = ${python_modules}")

  file(GENERATE
    OUTPUT  "${CMAKE_BINARY_DIR}/${python_destination}/vtkModuleCI/__init__.py"
    CONTENT "${InitContent}")
  install(
    FILES       "${CMAKE_BINARY_DIR}/${python_destination}/vtkModuleCI/__init__.py"
    DESTINATION "${python_destination}/vtkModuleCI/")

  # Install vtkModuleCIPython
  export(
    EXPORT    vtkModuleCIPython
    NAMESPACE VTKCI::
    FILE "${CMAKE_BINARY_DIR}/${python_destination}/vtkModuleCIPython/vtkModuleCIPython-targets.cmake")
  install(
    EXPORT    vtkModuleCIPython
    NAMESPACE VTKCI::
    FILE      vtkModuleCIPython-targets.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vtkModuleCIPython")

endif()

