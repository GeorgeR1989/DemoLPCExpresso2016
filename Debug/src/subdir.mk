################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DemoLPCExpresso2016.c \
../src/DemoLPCExpresso2016_init.c \
../src/Seven_Segment.c \
../src/buzzer.c \
../src/cr_startup_lpc11.c \
../src/display.c \
../src/joystickPosition.c \
../src/push_button.c \
../src/rotary_encoder.c \
../src/temperature.c 

OBJS += \
./src/DemoLPCExpresso2016.o \
./src/DemoLPCExpresso2016_init.o \
./src/Seven_Segment.o \
./src/buzzer.o \
./src/cr_startup_lpc11.o \
./src/display.o \
./src/joystickPosition.o \
./src/push_button.o \
./src/rotary_encoder.o \
./src/temperature.o 

C_DEPS += \
./src/DemoLPCExpresso2016.d \
./src/DemoLPCExpresso2016_init.d \
./src/Seven_Segment.d \
./src/buzzer.d \
./src/cr_startup_lpc11.d \
./src/display.d \
./src/joystickPosition.d \
./src/push_button.d \
./src/rotary_encoder.d \
./src/temperature.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -D_LPCXpresso_ -DDEBUG -D__CODE_RED -D__REDLIB__ -I"D:\work\tmp\src\Lib_CMSISv1p30_LPC11xx\inc" -I"D:\work\tmp\src\Lib_FatFs_SD\inc" -I"D:\work\tmp\src\Lib_EaBaseBoard\inc" -I"D:\work\tmp\src\Lib_MCU\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


