CMSIS_ROOT=/home/dek/prog/arm/lpc177x_8x

CC=arm-none-eabi-gcc
AS=arm-none-eabi-as

CFLAGS=-g -mthumb -mcpu=cortex-m3 -I $(CMSIS_ROOT)/Core/CMSIS/Include -I $(CMSIS_ROOT)/Core/Device/NXP/LPC177x_8x/Include -mfix-cortex-m3-ldrd
LDFLAGS=-L $(CMSIS_ROOT)/Core/CMSIS/Lib -L $(CMSIS_ROOT)/Core/Device/NXP/LPC177x_8x/Lib -mfix-cortex-m3-ldrd -T gcc.ld

all:
	arm-none-eabi-gcc $(CFLAGS) $(LDFLAGS) main.c system_LPC177x_8x.c startup_LPC177x_8x.s -lgcc --specs=nosys.specs 
	arm-none-eabi-objcopy -Obinary a.out a.bin
	arm-none-eabi-objdump -S a.out > a.list

clean:
	rm a.bin a.list a.out
	
