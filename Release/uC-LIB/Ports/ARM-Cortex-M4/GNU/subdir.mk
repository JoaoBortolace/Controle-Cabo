################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../uC-LIB/Ports/ARM-Cortex-M4/GNU/lib_mem_a.s 

OBJS += \
./uC-LIB/Ports/ARM-Cortex-M4/GNU/lib_mem_a.o 

S_DEPS += \
./uC-LIB/Ports/ARM-Cortex-M4/GNU/lib_mem_a.d 


# Each subdirectory must supply rules for building sources it contributes
uC-LIB/Ports/ARM-Cortex-M4/GNU/%.o: ../uC-LIB/Ports/ARM-Cortex-M4/GNU/%.s uC-LIB/Ports/ARM-Cortex-M4/GNU/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -c -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Config" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Inc" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/CMSIS/Include" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/System" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-CPU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-LIB" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-LIB/Cfg/Template" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/uC-OS3/Source" -I"C:/Users/borto/Documents/GitHub/Controle_Cabo_v2/Controle_Cabo/App/Src" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-uC-2d-LIB-2f-Ports-2f-ARM-2d-Cortex-2d-M4-2f-GNU

clean-uC-2d-LIB-2f-Ports-2f-ARM-2d-Cortex-2d-M4-2f-GNU:
	-$(RM) ./uC-LIB/Ports/ARM-Cortex-M4/GNU/lib_mem_a.d ./uC-LIB/Ports/ARM-Cortex-M4/GNU/lib_mem_a.o

.PHONY: clean-uC-2d-LIB-2f-Ports-2f-ARM-2d-Cortex-2d-M4-2f-GNU

