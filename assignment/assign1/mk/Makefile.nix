# Makefile for OOP345-BTP305 Assignments - Linux
#
###
# Only the two lines below this one may need be changed
T?=project
ARGV?=00-empty_object.json 01-empty_array.json 02-empty_array_with_empty_object.json
###


#  suppresses echoing the command before running it
.SILENT: all run clean
.IGNORE: clean

# some usage macros to prevent wrong makefile from being called
WELCOME='== OOP345/BTP305 Simple Build Tool for Unix/Linux =='
USAGE="Makefile.nix: Unix/Linux makefile; you probably want: 'nmake'"

####
# No need to change anything below this line when updating assignments
# as long as variables T and ARGV (above) are defined and all
# source files related to an assignment in the src directory
####

SRC=src

# set headers but prevent no-header found error
H=$(SRC)/*.h
HEADERS=$(shell echo $H)
ifeq ($H,$(HEADERS))
HEADERS=
endif

D=$(SRC)/*.cpp
DEPENDENCIES=$(shell echo $D)
ifeq ($D,$(DEPENDENCIES))
DEPENDENCIES=
endif


BIN=bin
TARGET=$(BIN)/$T.out
CXXFLAGS=-std=c++0x -Wall -g  -o$(TARGET)
RUN=./$A.out $(ARGV)

all: prebuild $(TARGET) run

prebuild: 
	@echo $(WELCOME)
	@touch $(DEPENDENCIES) $(HEADERS) 2>/dev/null || (echo 'No source files found';  exit 1)

run: prebuild
	@echo "Running Target...:" $(TARGET)
	@cd $(BIN); $(RUN)
	#@echo All done!

# remove target exe and bin directory, if empty; ignore errors
clean: 
	@echo $(WELCOME)
	@echo -n "Cleaning Up..."
	@rm -f $(TARGET) 2>/dev/null
	@[ -d $(BIN) ] && rmdir $(BIN) 2> /dev/null || echo -n .
	@echo "done!"

# compile all dependencies to make target
$(TARGET): $(HEADERS) $(DEPENDENCIES)
	@echo -n "Compiling.."
	@[ ! -d "$(BIN)" ] && mkdir "$(BIN)" || echo .
	$(CXX) $(CXXFLAGS) $(DEPENDENCIES)
	@echo "done!"

# vim:noet
