@echo off

:: EXE_NAME is name of executable, ARGV holds command line arguments to program
set EXE_NAME=project
set ARGV=

:: ------ USUALLY, NO CHANGES ARE NECESSARY BELOW THIS LINE
set WELCOME=== OOP345/BTP305 Simple Build Tool for Windows ==

if "%VCINSTALLDIR%" == "" (
  @echo %WELCOME%
  @echo You haven't setup your enviroment variables, run VSVARS32.BAT first.
  @echo **********************************************************************
  @echo VSVARS32.BAT is usually found in:
  @echo   C:\Program Files (x86^)\Microsoft Visual Studio 12.0\Common7\Tools
  @echo or
  @echo   C:\Program Files\Microsoft Visual Studio 12.0\Common7\Tools
  @echo or
  @echo   Check 'Common7\Tools' folder of where Visual Studio is installed.
  @echo **********************************************************************
  @call :cleanup
  exit /b 1
)

if "%1" == "help" goto help
if "%1" == "--help" goto help
if "%1" == "-h" goto help
if "%1" == "/h" goto help
if "%1" == "/?" goto help

if "%1%" == "clean" goto make

:: check if directory exists
if not exist src\"%ASGN_DIR%" (
  @echo %WELCOME%
  @echo src\%ASGN_DIR%: No such directory.
  @call :cleanup
  exit /b 1
)

:: check if source file exists
dir /b src\%ASGN_DIR%\*.cpp 1>NUL 2>&1

if ERRORLEVEL 1 (
  @echo %WELCOME%
  @echo src\%ASGN_DIR%: has no source files. Copy, or create, some source files there. 1>&2
  @call :cleanup
  exit /b 1
)

:make
nmake -f mk/Makefile %*
goto :eof

:help
(
  echo %WELCOME%
  echo Your options are:
  echo    build: to build target
  echo    build clean: to remove target and bin directory (if empty^)
  @call :cleanup
  exit /b 0
)
goto:eof

:: clean up intermediate artifacts from src (if any)
:cleanup
if exist src\%ASGN_DIR%\_THIS_EMPTY_HEADER_FILE_CAN_BE_DELETED_.h (
  @del /q src\%ASGN_DIR%\_THIS_EMPTY_HEADER_FILE_CAN_BE_DELETED_.h
)
goto :eof

:eof
