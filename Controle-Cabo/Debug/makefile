################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include uC-OS3/Template/subdir.mk
-include uC-OS3/TLS/NewLib/subdir.mk
-include uC-OS3/Source/subdir.mk
-include uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/subdir.mk
-include uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/subdir.mk
-include uC-LIB/Ports/ARM-Cortex-M4/GNU/subdir.mk
-include uC-LIB/subdir.mk
-include uC-CPU/ARM-Cortex-M/ARMv7-M/GNU/subdir.mk
-include uC-CPU/ARM-Cortex-M/ARMv7-M/subdir.mk
-include uC-CPU/subdir.mk
-include System/Startup/subdir.mk
-include System/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include App/Src/subdir.mk
-include App/Config/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Controle_Cabo
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Controle_Cabo.elf \

MAP_FILES += \
Controle_Cabo.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Controle_Cabo.list \


# All Target
all: main-build

# Main-build Target
main-build: Controle_Cabo.elf secondary-outputs

# Tool invocations
Controle_Cabo.elf Controle_Cabo.map: $(OBJS) $(USER_OBJS) C:\Users\borto\Documents\GitHub\Controle-Cabo\Controle-Cabo\System\STM32F439ZITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Controle_Cabo.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\borto\Documents\GitHub\Controle-Cabo\Controle-Cabo\System\STM32F439ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Controle_Cabo.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Controle_Cabo.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Controle_Cabo.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Controle_Cabo.elf Controle_Cabo.list Controle_Cabo.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
