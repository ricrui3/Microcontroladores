CC = avr-gcc
OBJCOPY = avr-objcopy

UISP = uisp -dprog=dapa -dlpt=0x378 --erase --upload --verify
FUSE = uisp -dprog=dapa -dlpt=0x378 --wr_fuse_l=0xff

MCU = atmega8535
FORMAT = ihex
F_CPU = 8000000

CFLAGS = -Wall --std=gnu99 -mmcu=$(MCU) -Os -DF_CPU=$(F_CPU)

%.o: %.c; $(CC) -c $(CFLAGS) -o $@ $<
%.hex: %.elf; $(OBJCOPY) -O $(FORMAT) $< $@

OBJS_INT = main-int.o usart.o util.o
OBJS_NOINT = main-noint.o usart.o util.o
OBJS = $(OBJS_INT) $(OBJS_NOINT)
ELFS = main-int.elf main-noint.elf
TARGET = main-int.hex main-noint.hex

all: $(TARGET)

main-int.hex: main-int.elf
main-noint.hex: main-noint.elf

main-int.elf: $(OBJS_INT)
	$(CC) $(CFLAGS) -o $@ $^

main-noint.elf: $(OBJS_NOINT)
	$(CC) $(CFLAGS) -o $@ $^

main-int.o: main-int.c usart.h util.h
main-noint.o: main-noint.c usart.h util.h
usart.o: usart.c usart.h
util.o: util.c util.h

uisp-int: main-int.hex
	$(UISP) if=$<

uisp-noint: main-noint.hex
	$(UISP) if=$<

fuse:
	$(FUSE)

clean:
	rm -f $(TARGET) $(ELFS) $(OBJS) *~
