@echo off
cls

set DRIVE_LETTER=%1:
set PATH=%DRIVE_LETTER%\TDM-GCC-64\bin;c:\windows
set PROJECT_PATH=.

mingw32-make DRIVE_LETTER="%DRIVE_LETTER%" PROJECT_PATH="%PROJECT_PATH%"
Graphs vertices.txt edges.txt
pause