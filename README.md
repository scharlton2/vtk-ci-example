Introduction
============
VTK CI Example is example on how to build and test a VTK based application or modules using CI.
It contains only a very simple VTK module associated with a `.gitlab-ci.yml` file.

All is handled in `.gitlab-ci.yml`, you can copy it to your own project
on any gitlab instance to be able to build and test your VTK based module or application.

This example is developed by [Kitware SAS][].

[Kitware SAS]: https://www.kitware.eu

Build and test with a VTK image
====================================
The provided `.gitlab-ci.yml` use VTK v9.1.0 to build and test.
To choose another version, just change the `image` tag in .gitlab-ci.yml to point to another image.
Available images are visible on [vtk-for-ci][] dockerhub repository.

Graphical testing is supported using a [Xvfb][] entry point.

[vtk-for-ci]: https://hub.docker.com/r/kitware/vtk-for-ci
[Xvfb]: https://en.wikipedia.org/wiki/Xvfb

License
=======

This repository is distributed under the OSI-approved BSD 3-clause License.
See [License.txt][] for details. For additional licenses, refer to the
[VTK License][].

[License.txt]: License.txt
[VTK License]: https://vtk.org/about/#license
