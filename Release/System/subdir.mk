################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/syscalls.c \
../System/sysmem.c \
../System/system_stm32f4xx.c 

OBJS += \
./System/syscalls.o \
./System/sysmem.o \
./System/system_stm32f4xx.o 

C_DEPS += \
./System/syscalls.d \
./System/sysmem.d \
./System/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
System/%.o System/%.su System/%.cyclo: ../System/%.c System/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F439xx -c -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/System" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-LIB/Cfg/Template" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Src" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/CMSIS/Include" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-System

clean-System:
	-$(RM) ./System/syscalls.cyclo ./System/syscalls.d ./System/syscalls.o ./System/syscalls.su ./System/sysmem.cyclo ./System/sysmem.d ./System/sysmem.o ./System/sysmem.su ./System/system_stm32f4xx.cyclo ./System/system_stm32f4xx.d ./System/system_stm32f4xx.o ./System/system_stm32f4xx.su

.PHONY: clean-System

