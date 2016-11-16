RM := rm -rf
CC = gcc
-include sources.mk
-include src/tool/subdir.mk
-include src/subdir.mk
USER_OBJS :=
LIBS := -lcurl

all: FlyGo

FlyGo: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC)  -o "build/bin/flygo-linux" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) FlyGo
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
