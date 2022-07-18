# makfile configuration
COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button-c.elf 

#additional rules for files
button-c.elf: ${COMMON_OBJECTS} led.o switches.o buzzer.o main.o p2_interrupt_handler.o wdInterruptHandler.o stateMachines.o state_advance-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button-c.elf
	msp430loader.sh button-c.elf

clean:
	rm -f *.o *.elf
