################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/motor_bobina.c \
../Core/Src/motor_transversal.c \
../Core/Src/opto.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/motor_bobina.o \
./Core/Src/motor_transversal.o \
./Core/Src/opto.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/motor_bobina.d \
./Core/Src/motor_transversal.d \
./Core/Src/opto.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F439xx -DUSE_FULL_LL_DRIVER -DHSE_VALUE=25000000U -c -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/BSP/Inc" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/CMSIS/Include" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Core/Inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motor_bobina.cyclo ./Core/Src/motor_bobina.d ./Core/Src/motor_bobina.o ./Core/Src/motor_bobina.su ./Core/Src/motor_transversal.cyclo ./Core/Src/motor_transversal.d ./Core/Src/motor_transversal.o ./Core/Src/motor_transversal.su ./Core/Src/opto.cyclo ./Core/Src/opto.d ./Core/Src/opto.o ./Core/Src/opto.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

