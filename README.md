# This sandbox project demonstrates how to create relocatable C++ applications (with plugins) on Windows, MacOS and Linux using CMake.
[![Build Actions Status](https://github.com/dyollb/bundle-app-sandbox/C/C++%20CI/badge.svg)](https://github.com/dyollb/bundle-app-sandbox/actions)

Bundling C++ applications on different platform can be tricky. While there are several examples of how to use CMake's BundleUtilities for simple executables, I found it difficult to apply this to executables with plugins, in particular on MacOS. After reading about the topic and searching for best practice / reference projects, I decided to create this little C++ template project.

References:

- <https://cmake.org/cmake/help/latest/module/BundleUtilities.html>
- <https://cmake.org/pipermail/cmake/2008-July/022989.html>
- <https://www.maketecheasier.com/anatomy-macos-app-bundles/>
- <https://github.com/RoysamLab/Farsight-toolkit/blob/7e9d6d15688735f34f7ca272e4e715acd11473ff/InstallRules/CompleteBundles.cmake.in>
- <https://cliutils.gitlab.io/modern-cmake/chapters/install/installing.html>
- <https://levelup.gitconnected.com/simple-modern-cmake-tutorial-part-2-285614d6a0ce>
