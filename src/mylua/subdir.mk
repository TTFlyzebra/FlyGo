################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mylua/loadlua.c \
../src/mylua/luafunc.c \
../src/mylua/luautils.c 

OBJS += \
./build/lib/mylua/loadlua.o \
./build/lib/mylua/luafunc.o \
./build/lib/mylua/luautils.o 

C_DEPS += \
./build/lib/mylua/loadlua.d \
./build/lib/mylua/luafunc.d \
./build/lib/mylua/luautils.d 


# Each subdirectory must supply rules for building sources it contributes
./build/lib/mylua/%.o: ./src/mylua/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


