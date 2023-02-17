################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/app.c 

OBJS += \
./app/app.o 

C_DEPS += \
./app/app.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o app/%.su: ../app/%.c app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/app" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/os" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/dictionary" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/communication" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/app/tasks" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/app/generated_tables" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/delay" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/hal" -I"C:/Users/home/STM32CubeIDE/workspace_1.10.1/ecu_base/commons/diagnostic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app

clean-app:
	-$(RM) ./app/app.d ./app/app.o ./app/app.su

.PHONY: clean-app

