################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
./src/FlyGo.c \
./src/curlsend.c \
./src/httpdata.c 

OBJS += \
./build/lib/FlyGo.o \
./build/lib/curlsend.o \
./build/lib/httpdata.o 

C_DEPS += \
./build/lib/FlyGo.d \
./build/lib/curlsend.d \
./build/lib/httpdata.d 


# Each subdirectory must supply rules for building sources it contributes
build/lib/%.o: src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	$(CC) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


