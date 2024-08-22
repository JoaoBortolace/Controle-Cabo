################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../uC-OS3/Source/os_cfg_app.c \
../uC-OS3/Source/os_core.c \
../uC-OS3/Source/os_dbg.c \
../uC-OS3/Source/os_flag.c \
../uC-OS3/Source/os_mem.c \
../uC-OS3/Source/os_msg.c \
../uC-OS3/Source/os_mutex.c \
../uC-OS3/Source/os_prio.c \
../uC-OS3/Source/os_q.c \
../uC-OS3/Source/os_sem.c \
../uC-OS3/Source/os_stat.c \
../uC-OS3/Source/os_task.c \
../uC-OS3/Source/os_tick.c \
../uC-OS3/Source/os_time.c \
../uC-OS3/Source/os_tmr.c \
../uC-OS3/Source/os_var.c 

OBJS += \
./uC-OS3/Source/os_cfg_app.o \
./uC-OS3/Source/os_core.o \
./uC-OS3/Source/os_dbg.o \
./uC-OS3/Source/os_flag.o \
./uC-OS3/Source/os_mem.o \
./uC-OS3/Source/os_msg.o \
./uC-OS3/Source/os_mutex.o \
./uC-OS3/Source/os_prio.o \
./uC-OS3/Source/os_q.o \
./uC-OS3/Source/os_sem.o \
./uC-OS3/Source/os_stat.o \
./uC-OS3/Source/os_task.o \
./uC-OS3/Source/os_tick.o \
./uC-OS3/Source/os_time.o \
./uC-OS3/Source/os_tmr.o \
./uC-OS3/Source/os_var.o 

C_DEPS += \
./uC-OS3/Source/os_cfg_app.d \
./uC-OS3/Source/os_core.d \
./uC-OS3/Source/os_dbg.d \
./uC-OS3/Source/os_flag.d \
./uC-OS3/Source/os_mem.d \
./uC-OS3/Source/os_msg.d \
./uC-OS3/Source/os_mutex.d \
./uC-OS3/Source/os_prio.d \
./uC-OS3/Source/os_q.d \
./uC-OS3/Source/os_sem.d \
./uC-OS3/Source/os_stat.d \
./uC-OS3/Source/os_task.d \
./uC-OS3/Source/os_tick.d \
./uC-OS3/Source/os_time.d \
./uC-OS3/Source/os_tmr.d \
./uC-OS3/Source/os_var.d 


# Each subdirectory must supply rules for building sources it contributes
uC-OS3/Source/%.o uC-OS3/Source/%.su uC-OS3/Source/%.cyclo: ../uC-OS3/Source/%.c uC-OS3/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-CPU/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-LIB/Ports/ARM-Cortex-M4/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Ports/ARM-Cortex-M/ARMv7-M/GNU" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/uC-OS3/Source" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Config" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/App/Src" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/Drivers/CMSIS/Include" -I"C:/Controle-Cabo/Controle-Cabo/Controle-Cabo/Controle-Cabo/System" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-uC-2d-OS3-2f-Source

clean-uC-2d-OS3-2f-Source:
	-$(RM) ./uC-OS3/Source/os_cfg_app.cyclo ./uC-OS3/Source/os_cfg_app.d ./uC-OS3/Source/os_cfg_app.o ./uC-OS3/Source/os_cfg_app.su ./uC-OS3/Source/os_core.cyclo ./uC-OS3/Source/os_core.d ./uC-OS3/Source/os_core.o ./uC-OS3/Source/os_core.su ./uC-OS3/Source/os_dbg.cyclo ./uC-OS3/Source/os_dbg.d ./uC-OS3/Source/os_dbg.o ./uC-OS3/Source/os_dbg.su ./uC-OS3/Source/os_flag.cyclo ./uC-OS3/Source/os_flag.d ./uC-OS3/Source/os_flag.o ./uC-OS3/Source/os_flag.su ./uC-OS3/Source/os_mem.cyclo ./uC-OS3/Source/os_mem.d ./uC-OS3/Source/os_mem.o ./uC-OS3/Source/os_mem.su ./uC-OS3/Source/os_msg.cyclo ./uC-OS3/Source/os_msg.d ./uC-OS3/Source/os_msg.o ./uC-OS3/Source/os_msg.su ./uC-OS3/Source/os_mutex.cyclo ./uC-OS3/Source/os_mutex.d ./uC-OS3/Source/os_mutex.o ./uC-OS3/Source/os_mutex.su ./uC-OS3/Source/os_prio.cyclo ./uC-OS3/Source/os_prio.d ./uC-OS3/Source/os_prio.o ./uC-OS3/Source/os_prio.su ./uC-OS3/Source/os_q.cyclo ./uC-OS3/Source/os_q.d ./uC-OS3/Source/os_q.o ./uC-OS3/Source/os_q.su ./uC-OS3/Source/os_sem.cyclo ./uC-OS3/Source/os_sem.d ./uC-OS3/Source/os_sem.o ./uC-OS3/Source/os_sem.su ./uC-OS3/Source/os_stat.cyclo ./uC-OS3/Source/os_stat.d ./uC-OS3/Source/os_stat.o ./uC-OS3/Source/os_stat.su ./uC-OS3/Source/os_task.cyclo ./uC-OS3/Source/os_task.d ./uC-OS3/Source/os_task.o ./uC-OS3/Source/os_task.su ./uC-OS3/Source/os_tick.cyclo ./uC-OS3/Source/os_tick.d ./uC-OS3/Source/os_tick.o ./uC-OS3/Source/os_tick.su ./uC-OS3/Source/os_time.cyclo ./uC-OS3/Source/os_time.d ./uC-OS3/Source/os_time.o ./uC-OS3/Source/os_time.su ./uC-OS3/Source/os_tmr.cyclo ./uC-OS3/Source/os_tmr.d ./uC-OS3/Source/os_tmr.o ./uC-OS3/Source/os_tmr.su ./uC-OS3/Source/os_var.cyclo ./uC-OS3/Source/os_var.d ./uC-OS3/Source/os_var.o ./uC-OS3/Source/os_var.su

.PHONY: clean-uC-2d-OS3-2f-Source

