RM := rm -rf
CC = arm-linux-androideabi-gcc -I/home/flyzebra/android-curl/include
-include sources.mk
-include src/tool/subdir.mk
-include src/subdir.mk
USER_OBJS :=
LIBS := /home/flyzebra/android-curl/lib/libcurl.a

all: FlyGo

FlyGo: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC)  -o "build/bin/flygo-android" $(OBJS) $(USER_OBJS) /home/flyzebra/android-curl/lib/libcurl.a
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FlyGo
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
