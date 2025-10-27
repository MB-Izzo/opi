@echo off
REM -------------------------------------------------
REM Build project with CMake + Ninja and copy compile_commands.json
REM -------------------------------------------------

REM Set paths to Clang if you want to force it (optional)
REM set CC=C:\Program Files\LLVM\bin\clang.exe
REM set CXX=C:\Program Files\LLVM\bin\clang++.exe

REM Configure CMake (generate Ninja build files)
REM cmake -G Ninja -B build_nvim -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -Wno-dev
cmake -G Ninja -B build_nvim -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -Wno-dev -DCMAKE_BUILD_TYPE=Release -DTRACY_PROFILING=ON

IF %ERRORLEVEL% NEQ 0 (
    echo CMake configuration failed!
    exit /b 1
)

REM Build the project
cmake --build build_nvim --config Release

IF %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b 1
)

REM Copy compile_commands.json to src folder
copy /Y build_nvim\compile_commands.json src\

IF %ERRORLEVEL% EQU 0 (
    echo compile_commands.json copied to src folder
) ELSE (
    echo Failed to copy compile_commands.json
    exit /b 1
)

echo Build completed successfully!
pause
