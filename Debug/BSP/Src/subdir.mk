################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/Src/bsp.c \
../BSP/Src/bsp_adc.c \
../BSP/Src/bsp_dac.c \
../BSP/Src/bsp_extInt.c \
../BSP/Src/bsp_flash.c \
../BSP/Src/bsp_gpio.c \
../BSP/Src/bsp_pwm.c \
../BSP/Src/bsp_tim.c 

OBJS += \
./BSP/Src/bsp.o \
./BSP/Src/bsp_adc.o \
./BSP/Src/bsp_dac.o \
./BSP/Src/bsp_extInt.o \
./BSP/Src/bsp_flash.o \
./BSP/Src/bsp_gpio.o \
./BSP/Src/bsp_pwm.o \
./BSP/Src/bsp_tim.o 

C_DEPS += \
./BSP/Src/bsp.d \
./BSP/Src/bsp_adc.d \
./BSP/Src/bsp_dac.d \
./BSP/Src/bsp_extInt.d \
./BSP/Src/bsp_flash.d \
./BSP/Src/bsp_gpio.d \
./BSP/Src/bsp_pwm.d \
./BSP/Src/bsp_tim.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/Src/%.o BSP/Src/%.su BSP/Src/%.cyclo: ../BSP/Src/%.c BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F439xx -DUSE_FULL_LL_DRIVER -DHSE_VALUE=25000000U -c -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/BSP/Inc" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/CMSIS/Include" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle_CABO/CC_Cabo/C_Cabo/Controle_Cabo/Core/Inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-Src

clean-BSP-2f-Src:
	-$(RM) ./BSP/Src/bsp.cyclo ./BSP/Src/bsp.d ./BSP/Src/bsp.o ./BSP/Src/bsp.su ./BSP/Src/bsp_adc.cyclo ./BSP/Src/bsp_adc.d ./BSP/Src/bsp_adc.o ./BSP/Src/bsp_adc.su ./BSP/Src/bsp_dac.cyclo ./BSP/Src/bsp_dac.d ./BSP/Src/bsp_dac.o ./BSP/Src/bsp_dac.su ./BSP/Src/bsp_extInt.cyclo ./BSP/Src/bsp_extInt.d ./BSP/Src/bsp_extInt.o ./BSP/Src/bsp_extInt.su ./BSP/Src/bsp_flash.cyclo ./BSP/Src/bsp_flash.d ./BSP/Src/bsp_flash.o ./BSP/Src/bsp_flash.su ./BSP/Src/bsp_gpio.cyclo ./BSP/Src/bsp_gpio.d ./BSP/Src/bsp_gpio.o ./BSP/Src/bsp_gpio.su ./BSP/Src/bsp_pwm.cyclo ./BSP/Src/bsp_pwm.d ./BSP/Src/bsp_pwm.o ./BSP/Src/bsp_pwm.su ./BSP/Src/bsp_tim.cyclo ./BSP/Src/bsp_tim.d ./BSP/Src/bsp_tim.o ./BSP/Src/bsp_tim.su

.PHONY: clean-BSP-2f-Src

