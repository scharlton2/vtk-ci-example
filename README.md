Introduction
============
VTK CI Example is an example on how to build and test a VTK based application or modules using CI.
It contains only a very simple VTK module associated with `.gitlab-ci.yml` and `.github/workflows/ci.yml` files.

Everything is handled in the yml files. You can copy the one you need in your own project,
on any gitlab instance or on github to be able to build and test your VTK based modules or applications.

This example is developed by [Kitware SAS][].

[Kitware SAS]: https://www.kitware.eu

Build and test with a VTK image
====================================
The provided yml files use VTK v9.1.0 to build and test.
To choose another version, just change the `image` tag in your yml file to point to another image.
Available images are visible on [vtk-for-ci][] dockerhub repository.

Graphical testing is supported using [xvfb-run][] and mesa.

[vtk-for-ci]: https://hub.docker.com/r/kitware/vtk-for-ci
[xvfb-run]: https://en.wikipedia.org/wiki/Xvfb

License
=======

This repository is distributed under the OSI-approved BSD 3-clause License.
The yml files in the repository can alternatively be used under the CC0 license
and, as such, can be copied without mentioning Kitware copyright.
See [License.txt][] for details. For additional licenses, refer to the
[VTK License][].

[License.txt]: License.txt
[VTK License]: https://vtk.org/about/#license
