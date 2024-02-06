@echo off

rem Set C++ compiler
set "CXX=g++"

rem Create build folder
mkdir build
cd build

rem Set prefer compiler
cmake -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=%CXX% -DCMAKE_EXE_LINKER_FLAGS="-mwindows" ..

rem Build project
cmake --build . --config Release

rem Copy Assets directory
cd ..
xcopy /s /y /i "Assets" "./build/Assets/"
