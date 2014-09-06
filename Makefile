all: Tetris.hex

Tetris.elf: Tetris.c Resources.c GLI.c NT7108.c
	avr-gcc -DF_CPU=16000000 -Os -Wall -mmcu=atmega324p -o $@ $^

Tetris.hex: Tetris.elf
	avr-objcopy -j .text -j .data -O ihex $< $@
	avr-size Tetris.elf

clean:
	$(RM) Tetris.elf Tetris.hex

.PHONY: all clean