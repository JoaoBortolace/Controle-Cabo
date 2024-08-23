################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/os_cpu_a.S 

OBJS += \
./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/os_cpu_a.o 

S_UPPER_DEPS += \
./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/os_cpu_a.d 


# Each subdirectory must supply rules for building sources it contributes
uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/%.o: ../uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/%.S uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -c -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/System" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-uC-2d-OS3-2f-Ports-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M-2f-GNU

clean-uC-2d-OS3-2f-Ports-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M-2f-GNU:
	-$(RM) ./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/os_cpu_a.d ./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU/os_cpu_a.o

.PHONY: clean-uC-2d-OS3-2f-Ports-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M-2f-GNU

