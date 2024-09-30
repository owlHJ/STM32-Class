################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c 

OBJS += \
./Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.o 

C_DEPS += \
./Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.o: C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.c Drivers/BSP/STM32F1xx_Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DUSE_STM32F1xx_NUCLEO -c -I../../../Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../../../../../../../../Drivers/STM32F1xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32F1xx_Nucleo -I../../../../../../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F1xx_Nucleo

clean-Drivers-2f-BSP-2f-STM32F1xx_Nucleo:
	-$(RM) ./Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.cyclo ./Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.d ./Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.o ./Drivers/BSP/STM32F1xx_Nucleo/stm32f1xx_nucleo.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32F1xx_Nucleo

