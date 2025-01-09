## OPENCL SDK INSTALL
https://github.com/LETI-MOEVM/labs-PA-24/tree/main/OCL_test

## GPU AMD problem resolve
https://github.com/ptrumpis/OpenCL-AMD-GPU?ysclid=m4flr3ruyr790749703

## Commands for run:
cmake -S . -B .\build -D CMAKE_PREFIX_PATH="your/path/to/opencl/sdk"

cmake --build .\build --config Release

.\build\Release\lab5.exe
