################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
./src/tool/tool_file.c \
./src/tool/tool_rand.c \
./src/tool/tool_sleep.c \
./src/tool/tool_string.c \
./src/tool/tool_time.c \
./src/tool/tool_url.c \
./src/tool/tool_utils.c 

OBJS += \
./build/lib/tool/tool_file.o \
./build/lib/tool/tool_rand.o \
./build/lib/tool/tool_sleep.o \
./build/lib/tool/tool_string.o \
./build/lib/tool/tool_time.o \
./build/lib/tool/tool_url.o \
./build/lib/tool/tool_utils.o 

C_DEPS += \
./build/lib/tool/tool_file.d \
./build/lib/tool/tool_rand.d \
./build/lib/tool/tool_sleep.d \
./build/lib/tool/tool_string.d \
./build/lib/tool/tool_time.d \
./build/lib/tool/tool_url.d \
./build/lib/tool/tool_utils.d 


# Each subdirectory must supply rules for building sources it contributes
bulid/lib/tool/%.o: src/tool/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	$(CC) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


