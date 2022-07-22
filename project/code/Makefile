# makfile configuration
COMMON_OBJECTS  = main.o led.o switches.o buzzer.o p2_interrupt_handler.o wdInterruptHandler.o stateMachines.o 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button-c.elf button-s.elf

#additional rules for files
button-c.elf: ${COMMON_OBJECTS} state_advance-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
	
button-s.elf: ${COMMON_OBJECTS} state_advance-s.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button-c.elf
	msp430loader.sh button-c.elf
	
load-s: button-s.elf
	msp430loader.sh

clean:
	rm -f *.o *.elf
	
led.o: led.c led.h switches.h
switches.o: switches.c switches.h led.h buzzer.h
stateMachines.o: led.h stateMachines.h buzzer.h
buzzer.o: buzzer.h
main.o: buzzer.h led.h switches.h
state_advance-c.o: switches.h stateMachines.h select_SM.h
