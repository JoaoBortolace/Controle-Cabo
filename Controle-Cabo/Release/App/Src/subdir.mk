################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/bobina.c \
../App/Src/carroTransversal.c \
../App/Src/main.c \
../App/Src/perifericos.c \
../App/Src/stm32f4xx_hal_msp.c \
../App/Src/stm32f4xx_it.c 

OBJS += \
./App/Src/bobina.o \
./App/Src/carroTransversal.o \
./App/Src/main.o \
./App/Src/perifericos.o \
./App/Src/stm32f4xx_hal_msp.o \
./App/Src/stm32f4xx_it.o 

C_DEPS += \
./App/Src/bobina.d \
./App/Src/carroTransversal.d \
./App/Src/main.d \
./App/Src/perifericos.d \
./App/Src/stm32f4xx_hal_msp.d \
./App/Src/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su App/Src/%.cyclo: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle-Cabo/Controle-Cabo/System" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/bobina.cyclo ./App/Src/bobina.d ./App/Src/bobina.o ./App/Src/bobina.su ./App/Src/carroTransversal.cyclo ./App/Src/carroTransversal.d ./App/Src/carroTransversal.o ./App/Src/carroTransversal.su ./App/Src/main.cyclo ./App/Src/main.d ./App/Src/main.o ./App/Src/main.su ./App/Src/perifericos.cyclo ./App/Src/perifericos.d ./App/Src/perifericos.o ./App/Src/perifericos.su ./App/Src/stm32f4xx_hal_msp.cyclo ./App/Src/stm32f4xx_hal_msp.d ./App/Src/stm32f4xx_hal_msp.o ./App/Src/stm32f4xx_hal_msp.su ./App/Src/stm32f4xx_it.cyclo ./App/Src/stm32f4xx_it.d ./App/Src/stm32f4xx_it.o ./App/Src/stm32f4xx_it.su

.PHONY: clean-App-2f-Src

