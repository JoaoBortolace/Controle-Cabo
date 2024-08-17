################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../System/Startup/startup_stm32f439zitx.s 

OBJS += \
./System/Startup/startup_stm32f439zitx.o 

S_DEPS += \
./System/Startup/startup_stm32f439zitx.d 


# Each subdirectory must supply rules for building sources it contributes
System/Startup/%.o: ../System/Startup/%.s System/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/CMSIS/Include" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/System" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-LIB/Cfg/Template" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Src" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-System-2f-Startup

clean-System-2f-Startup:
	-$(RM) ./System/Startup/startup_stm32f439zitx.d ./System/Startup/startup_stm32f439zitx.o

.PHONY: clean-System-2f-Startup

