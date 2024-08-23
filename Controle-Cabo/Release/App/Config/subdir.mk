################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Config/os_app_hooks.c 

OBJS += \
./App/Config/os_app_hooks.o 

C_DEPS += \
./App/Config/os_app_hooks.d 


# Each subdirectory must supply rules for building sources it contributes
App/Config/%.o App/Config/%.su App/Config/%.cyclo: ../App/Config/%.c App/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/System" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Config

clean-App-2f-Config:
	-$(RM) ./App/Config/os_app_hooks.cyclo ./App/Config/os_app_hooks.d ./App/Config/os_app_hooks.o ./App/Config/os_app_hooks.su

.PHONY: clean-App-2f-Config

