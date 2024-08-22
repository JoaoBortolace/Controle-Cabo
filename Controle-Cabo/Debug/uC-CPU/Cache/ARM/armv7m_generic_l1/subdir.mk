################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.c 

OBJS += \
./uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.o 

C_DEPS += \
./uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.d 


# Each subdirectory must supply rules for building sources it contributes
uC-CPU/Cache/ARM/armv7m_generic_l1/%.o uC-CPU/Cache/ARM/armv7m_generic_l1/%.su uC-CPU/Cache/ARM/armv7m_generic_l1/%.cyclo: ../uC-CPU/Cache/ARM/armv7m_generic_l1/%.c uC-CPU/Cache/ARM/armv7m_generic_l1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/System" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uC-2d-CPU-2f-Cache-2f-ARM-2f-armv7m_generic_l1

clean-uC-2d-CPU-2f-Cache-2f-ARM-2f-armv7m_generic_l1:
	-$(RM) ./uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.cyclo ./uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.d ./uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.o ./uC-CPU/Cache/ARM/armv7m_generic_l1/cpu_cache_armv7m_generic_l1.su

.PHONY: clean-uC-2d-CPU-2f-Cache-2f-ARM-2f-armv7m_generic_l1

