################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/tasks/task_0.c \
../app/tasks/task_1.c \
../app/tasks/task_diag.c 

OBJS += \
./app/tasks/task_0.o \
./app/tasks/task_1.o \
./app/tasks/task_diag.o 

C_DEPS += \
./app/tasks/task_0.d \
./app/tasks/task_1.d \
./app/tasks/task_diag.d 


# Each subdirectory must supply rules for building sources it contributes
app/tasks/%.o app/tasks/%.su: ../app/tasks/%.c app/tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/app" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/os" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/dictionary" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/communication" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/app/tasks" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/app/generated_tables" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/delay" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/hal" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/diagnostic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-tasks

clean-app-2f-tasks:
	-$(RM) ./app/tasks/task_0.d ./app/tasks/task_0.o ./app/tasks/task_0.su ./app/tasks/task_1.d ./app/tasks/task_1.o ./app/tasks/task_1.su ./app/tasks/task_diag.d ./app/tasks/task_diag.o ./app/tasks/task_diag.su

.PHONY: clean-app-2f-tasks

