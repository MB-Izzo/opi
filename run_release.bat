@echo off

REM Build the project
cmake --build build_nvim --config Release

IF %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b 1
)

echo Build completed successfully!
echo Running game

.\build_nvim\src\game\game.exe

pause
