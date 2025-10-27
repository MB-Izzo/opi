@echo off

REM Build the project
cmake --build build_nvim --config Debug

IF %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b 1
)

echo Build completed successfully!

pause
