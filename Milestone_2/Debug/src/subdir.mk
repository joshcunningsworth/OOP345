################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CustomerOrder.cpp \
../src/Item.cpp \
../src/Milestone_2.cpp \
../src/Utilities.cpp 

OBJS += \
./src/CustomerOrder.o \
./src/Item.o \
./src/Milestone_2.o \
./src/Utilities.o 

CPP_DEPS += \
./src/CustomerOrder.d \
./src/Item.d \
./src/Milestone_2.d \
./src/Utilities.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


