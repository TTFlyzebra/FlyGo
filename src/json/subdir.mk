################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
	
C_SRCS += \
./src/json/cJSON.c \
./src/json/fpconv.c \
./src/json/lua_cjson.c \
./src/json/strbuf.c 

OBJS += \
./build/lib/json/cJSON.o \
./build/lib/json/fpconv.o \
./build/lib/json/lua_cjson.o \
./build/lib/json/strbuf.o 

C_DEPS += \
./build/lib/json/cJSON.d \
./build/lib/json/fpconv.d \
./build/lib/json/lua_cjson.d\
./build/lib/json/strbuf.d 


# Each subdirectory must supply rules for building sources it contributes
./build/lib/json/%.o: ./src/json/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	$(CC) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


