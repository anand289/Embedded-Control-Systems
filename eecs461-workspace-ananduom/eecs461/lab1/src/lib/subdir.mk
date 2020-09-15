################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/lib/LPUART.c" \
"../src/lib/eecs461.c" \
"../src/lib/gpio_template.c" \
"../src/lib/interrupt_manager.c" \

C_SRCS += \
../src/lib/LPUART.c \
../src/lib/eecs461.c \
../src/lib/gpio_template.c \
../src/lib/interrupt_manager.c \

OBJS_OS_FORMAT += \
./src/lib/LPUART.o \
./src/lib/eecs461.o \
./src/lib/gpio_template.o \
./src/lib/interrupt_manager.o \

C_DEPS_QUOTED += \
"./src/lib/LPUART.d" \
"./src/lib/eecs461.d" \
"./src/lib/gpio_template.d" \
"./src/lib/interrupt_manager.d" \

OBJS += \
./src/lib/LPUART.o \
./src/lib/eecs461.o \
./src/lib/gpio_template.o \
./src/lib/interrupt_manager.o \

OBJS_QUOTED += \
"./src/lib/LPUART.o" \
"./src/lib/eecs461.o" \
"./src/lib/gpio_template.o" \
"./src/lib/interrupt_manager.o" \

C_DEPS += \
./src/lib/LPUART.d \
./src/lib/eecs461.d \
./src/lib/gpio_template.d \
./src/lib/interrupt_manager.d \


# Each subdirectory must supply rules for building sources it contributes
src/lib/LPUART.o: ../src/lib/LPUART.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/LPUART.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/lib/LPUART.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/eecs461.o: ../src/lib/eecs461.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/eecs461.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/lib/eecs461.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/gpio_template.o: ../src/lib/gpio_template.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/gpio_template.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/lib/gpio_template.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lib/interrupt_manager.o: ../src/lib/interrupt_manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lib/interrupt_manager.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/lib/interrupt_manager.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


