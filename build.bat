@echo off

setlocal enabledelayedexpansion

set mode=release
set outDir=bin
set outname=main.exe
set sourceDir=src
set dependendyDir=dependencies

rem Check if an argument is provided
if "%~1"=="" (
    set mode=debug
    rem set build=%~1
)

echo Build %mode% candidate...

rem create out folders
mkdir %outDir%\release 2>nul
mkdir %outDir%\debug 2>nul
del /q %outDir%\release\%outname% 2>nul
del /q %outDir%\debug\%outname% 2>nul

rem find all cpp recusive in sorce dir
set files=
for /R "%sourceDir%" %%F in (*.cpp) do (
    set "files=!files! "%%F""
)

set options=

if "%mode%"=="debug" (
    set options=-fdiagnostics-color=always -g -Og
)

g++ ^
    %options% ^
    !files! ^
    -o %outDir%\%mode%\%outname% ^
    -I%dependendyDir%/include ^
    -L%dependendyDir%/lib

endlocal
