################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.c 

OBJS += \
./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.o 

C_DEPS += \
./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.d 


# Each subdirectory must supply rules for building sources it contributes
uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/%.o uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/%.su uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/%.cyclo: ../uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/%.c uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/System" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uC-2d-OS3-2f-Ports-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M

clean-uC-2d-OS3-2f-Ports-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M:
	-$(RM) ./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.cyclo ./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.d ./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.o ./uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/os_cpu_c.su

.PHONY: clean-uC-2d-OS3-2f-Ports-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M

