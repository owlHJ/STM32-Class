################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Projects/STM32F103RB-Nucleo/Examples/GPIO/GPIO_IOToggle/SW4STM32/startup_stm32f103xb.s 

OBJS += \
./Example/SW4STM32/startup_stm32f103xb.o 

S_DEPS += \
./Example/SW4STM32/startup_stm32f103xb.d 


# Each subdirectory must supply rules for building sources it contributes
Example/SW4STM32/startup_stm32f103xb.o: C:/Users/USER/Desktop/24-2/STM/ATOM_Study/STM32Cube_FW_F1_V1.8.0/Projects/STM32F103RB-Nucleo/Examples/GPIO/GPIO_IOToggle/SW4STM32/startup_stm32f103xb.s Example/SW4STM32/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Example-2f-SW4STM32

clean-Example-2f-SW4STM32:
	-$(RM) ./Example/SW4STM32/startup_stm32f103xb.d ./Example/SW4STM32/startup_stm32f103xb.o

.PHONY: clean-Example-2f-SW4STM32

