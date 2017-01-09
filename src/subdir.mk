################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
./src/FlyGo.c \
./src/httpdata.c \
./src/kvcollect.c \
./src/kvcollectdata1.c \
./src/livemsg_getadlist.c 

OBJS += \
./build/lib/FlyGo.o \
./build/lib/httpdata.o \
./build/lib/kvcollect.o \
./build/lib/kvcollectdata1.o \
./build/lib/livemsg_getadlist.o 

C_DEPS += \
./build/lib/FlyGo.d \
./build/lib/httpdata.d \
./build/lib/kvcollect.d \
./build/lib/kvcollectdata1.d \
./build/lib/livemsg_getadlist.d 


# Each subdirectory must supply rules for building sources it contributes
build/lib/%.o: ./src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
