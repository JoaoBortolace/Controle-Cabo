################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.c 

OBJS += \
./uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.o 

C_DEPS += \
./uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.d 


# Each subdirectory must supply rules for building sources it contributes
uC-CPU/ARM-Cortex-M/ARMv7-M/%.o uC-CPU/ARM-Cortex-M/ARMv7-M/%.su uC-CPU/ARM-Cortex-M/ARMv7-M/%.cyclo: ../uC-CPU/ARM-Cortex-M/ARMv7-M/%.c uC-CPU/ARM-Cortex-M/ARMv7-M/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/System" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uC-2d-CPU-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M

clean-uC-2d-CPU-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M:
	-$(RM) ./uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.cyclo ./uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.d ./uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.o ./uC-CPU/ARM-Cortex-M/ARMv7-M/cpu_c.su

.PHONY: clean-uC-2d-CPU-2f-ARM-2d-Cortex-2d-M-2f-ARMv7-2d-M

