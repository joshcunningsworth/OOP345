# Makefile for OOP345-BTP305 Assignments - Windows
#
###
# Only the two lines below this one may need be changed
T=project
CMDLINEARGS=00-empty_object.json 01-empty_array.json 02-empty_array_with_empty_object.json
###

####
# No need to change anything below this line when updating assignments
# as long as variables T and CMDLINEARGS (above) are defined and all
# source files related to an assignment in the src directory
####

# some usage macros to prevent wrong makefile from being called
WELCOME='== OOP345/BTP305 Simple Build Tool for Windows =='
USAGE="Makefile for Windows. You probaby want 'make -f Makefile.nix'"

!IF "$(EXE_NAME)" != "" 
T=$(EXE_NAME)
!ENDIF

!IF "$(ARGV)" != "" 
CMDLINEARGS=$(ARGV)
!ENDIF

SRC=..\src
HEADERS=$(SRC)\*.h
DEPENDENCIES=$(SRC)\*.cpp

BIN=..\bin
CXXFLAGS=/nologo /EHsc /Fe$(TARGET)
TARGET=$(BIN)\$T.exe
RUN=$T.exe $(CMDLINEARGS)


##-- BEGIN HACK
# HEMPTY variable is needed for the special case when no headers are present
# in the source directory, we create an empty .h file and delete it later.
HEMPTY=$(SRC)\_THIS_EMPTY_HEADER_FILE_CAN_BE_DELETED_.h

all:
	@cd mk
	@echo $(WELCOME)
!ifdef COMSPEC
	
	- @<<headers.bat
	@(dir $(HEADERS) /b 2>&1|@%WINDIR%\system32\find /c "File Not Found")>>_HFOUNDRESULT_.TMP
	@set /p NOHFOUND=<_HFOUNDRESULT_.TMP
	@if "%NOHFOUND%" == "1" @TYPE NUL > $(HEMPTY)
<<
	- @del _HFOUNDRESULT_.TMP 2>NUL

	@nmake /nologo $(TARGET) run
!else
!error  $(USAGE) 
!endif
# -- END HACK

run: $(TARGET)
	@echo "Running Target...:" $(TARGET)
	@cd $(BIN)
	@$(RUN)
#	@echo All done!

# remove target exe and bin directory, if empty; (-) means ignore errors 
clean: 
	@cd mk
	@echo $(WELCOME)
	@echo -n "Cleaning Up..."
	@IF EXIST $(TARGET) del $(TARGET)
	- @rd $(BIN) 2>NUL
	- @del *.obj 2>NUL
	@echo "done!"

# NOTE: do not make changes here; add .cpp/.h to DEPENDENCIES/HEADERS above 
#	----	but that should not be needed really since default is get all files
#	
# compile all dependencies; remove intermediate obj files
$(TARGET): $(HEADERS) $(DEPENDENCIES)
	@IF NOT EXIST $(BIN) mkdir $(BIN)
	$(CXX) $(CXXFLAGS) $(DEPENDENCIES)
	@echo "Removing obj,temp Files..."
	- @del *.obj  2>NUL
	- @del $(HEMPTY) 2>NUL

# vim: noet
