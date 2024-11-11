#Makefile
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as

OUT             = button.elf

all: $(OUT)

button.elf: ${COMMON_OBJECTS} main.o switches.o led.o alarm.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

main.o: main.c
	${CC} ${CFLAGS} -c main.c -o main.o

switches.o: switches.c switches.h
	${CC} ${CFLAGS} -c switches.c -o switches.o

led.o: led.c led.h
	${CC} ${CFLAGS} -c led.c -o led.o

alarm.o: alarm.c alarm.h
	${CC} ${CFLAGS} -c alarm.c -o alarm.o

clean:
	rm -f *.o *.elf

load: $(OUT)
	@echo "Loading $(OUT) onto the MSP430..."
	./msp430loader.sh $(OUT)

size: $(OUT)
	msp430-elf-size $(OUT)
