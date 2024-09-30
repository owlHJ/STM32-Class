################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Projects/STM32F103RB-Nucleo/Examples/GPIO/GPIO_IOToggle/Src/main.c \
C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Projects/STM32F103RB-Nucleo/Examples/GPIO/GPIO_IOToggle/Src/stm32f1xx_it.c 

OBJS += \
./Example/User/main.o \
./Example/User/stm32f1xx_it.o 

C_DEPS += \
./Example/User/main.d \
./Example/User/stm32f1xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Example/User/main.o: C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Projects/STM32F103RB-Nucleo/Examples/GPIO/GPIO_IOToggle/Src/main.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DUSE_STM32F1xx_NUCLEO -c -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../../../../../../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32F1xx_Nucleo -I../../../../../../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Example/User/stm32f1xx_it.o: C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Projects/STM32F103RB-Nucleo/Examples/GPIO/GPIO_IOToggle/Src/stm32f1xx_it.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DUSE_STM32F1xx_NUCLEO -c -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../../../../../../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32F1xx_Nucleo -I../../../../../../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Example-2f-User

clean-Example-2f-User:
	-$(RM) ./Example/User/main.cyclo ./Example/User/main.d ./Example/User/main.o ./Example/User/main.su ./Example/User/stm32f1xx_it.cyclo ./Example/User/stm32f1xx_it.d ./Example/User/stm32f1xx_it.o ./Example/User/stm32f1xx_it.su

.PHONY: clean-Example-2f-User

