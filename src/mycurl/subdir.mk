################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
./src/mycurl/curlutils.c 

OBJS += \
./build/lib/mycurl/curlutils.o 

C_DEPS += \
./build/lib/mycurl/curlutils.d 


# Each subdirectory must supply rules for building sources it contributes
build/lib/mycurl/%.o: ./src/mycurl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


