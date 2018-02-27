	@(dir ..\src\*.h /b 2>&1|@%WINDIR%\system32\find /c "File Not Found")>>_HFOUNDRESULT_.TMP
	@set /p NOHFOUND=<_HFOUNDRESULT_.TMP
	@if "%NOHFOUND%" == "1" @TYPE NUL > ..\src\_THIS_EMPTY_HEADER_FILE_CAN_BE_DELETED_.h
