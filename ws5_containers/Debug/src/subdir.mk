################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Message.cpp \
../src/Notifications.cpp \
../src/ws5_containers.cpp 

OBJS += \
./src/Message.o \
./src/Notifications.o \
./src/ws5_containers.o 

CPP_DEPS += \
./src/Message.d \
./src/Notifications.d \
./src/ws5_containers.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


