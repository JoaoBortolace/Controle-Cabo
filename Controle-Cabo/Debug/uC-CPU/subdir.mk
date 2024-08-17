################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uC-CPU/cpu_core.c 

OBJS += \
./uC-CPU/cpu_core.o 

C_DEPS += \
./uC-CPU/cpu_core.d 


# Each subdirectory must supply rules for building sources it contributes
uC-CPU/%.o uC-CPU/%.su uC-CPU/%.cyclo: ../uC-CPU/%.c uC-CPU/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F439xx -c -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/System" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB/Cfg/Template" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uC-2d-CPU

clean-uC-2d-CPU:
	-$(RM) ./uC-CPU/cpu_core.cyclo ./uC-CPU/cpu_core.d ./uC-CPU/cpu_core.o ./uC-CPU/cpu_core.su

.PHONY: clean-uC-2d-CPU

