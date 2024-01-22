################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
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

BUILD_ARTIFACT_NAME := RoboTrcae_2023_TestProject
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
RoboTrcae_2023_TestProject.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RoboTrcae_2023_TestProject.list \

OBJCOPY_BIN += \
RoboTrcae_2023_TestProject.bin \


# All Target
all: main-build

# Main-build Target
main-build: RoboTrcae_2023_TestProject.elf secondary-outputs

# Tool invocations
RoboTrcae_2023_TestProject.elf: $(OBJS) $(USER_OBJS) C:\Users\youto\STM32CubeIDE\workspace_1.5.1\RoboTrcae_2023_TestProject\STM32F405RGTX_FLASH.ld
	arm-none-eabi-gcc -o "RoboTrcae_2023_TestProject.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\youto\STM32CubeIDE\workspace_1.5.1\RoboTrcae_2023_TestProject\STM32F405RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="RoboTrcae_2023_TestProject.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RoboTrcae_2023_TestProject.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RoboTrcae_2023_TestProject.list"
	@echo 'Finished building: $@'
	@echo ' '

RoboTrcae_2023_TestProject.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "RoboTrcae_2023_TestProject.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
