################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uC-LIB/lib_ascii.c \
../uC-LIB/lib_math.c \
../uC-LIB/lib_mem.c \
../uC-LIB/lib_str.c 

OBJS += \
./uC-LIB/lib_ascii.o \
./uC-LIB/lib_math.o \
./uC-LIB/lib_mem.o \
./uC-LIB/lib_str.o 

C_DEPS += \
./uC-LIB/lib_ascii.d \
./uC-LIB/lib_math.d \
./uC-LIB/lib_mem.d \
./uC-LIB/lib_str.d 


# Each subdirectory must supply rules for building sources it contributes
uC-LIB/%.o uC-LIB/%.su uC-LIB/%.cyclo: ../uC-LIB/%.c uC-LIB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/System" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uC-2d-LIB

clean-uC-2d-LIB:
	-$(RM) ./uC-LIB/lib_ascii.cyclo ./uC-LIB/lib_ascii.d ./uC-LIB/lib_ascii.o ./uC-LIB/lib_ascii.su ./uC-LIB/lib_math.cyclo ./uC-LIB/lib_math.d ./uC-LIB/lib_math.o ./uC-LIB/lib_math.su ./uC-LIB/lib_mem.cyclo ./uC-LIB/lib_mem.d ./uC-LIB/lib_mem.o ./uC-LIB/lib_mem.su ./uC-LIB/lib_str.cyclo ./uC-LIB/lib_str.d ./uC-LIB/lib_str.o ./uC-LIB/lib_str.su

.PHONY: clean-uC-2d-LIB

