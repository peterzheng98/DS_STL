#!/bin/bash

if [ ! -f "vcpkg/bootstrap-vcpkg.sh" ] ; then git clone https://github.com/Microsoft/vcpkg.git && cd vcpkg && ./bootstrap-vcpkg.sh && cd ..; fi
export VCPKG_ROOT=$(pwd)/vcpkg
cd vcpkg && ./vcpkg install gtest benchmark && rm -rf buildtrees
cd ..

cmake -H. -Bcmake-build -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cd cmake-build && cmake --build .
./DequeTest
./DequeTestBench
time ./DequeBench
echo "Done!"
