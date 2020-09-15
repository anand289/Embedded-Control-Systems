################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/lab1/lab1_template.c" \

C_SRCS += \
../src/lab1/lab1_template.c \

OBJS_OS_FORMAT += \
./src/lab1/lab1_template.o \

C_DEPS_QUOTED += \
"./src/lab1/lab1_template.d" \

OBJS += \
./src/lab1/lab1_template.o \

OBJS_QUOTED += \
"./src/lab1/lab1_template.o" \

C_DEPS += \
./src/lab1/lab1_template.d \


# Each subdirectory must supply rules for building sources it contributes
src/lab1/lab1_template.o: ../src/lab1/lab1_template.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lab1/lab1_template.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/lab1/lab1_template.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


