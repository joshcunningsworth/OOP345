################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Product.cpp \
../src/Sale.cpp \
../src/ws7_STLcontainers.cpp 

OBJS += \
./src/Product.o \
./src/Sale.o \
./src/ws7_STLcontainers.o 

CPP_DEPS += \
./src/Product.d \
./src/Sale.d \
./src/ws7_STLcontainers.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


