CC = ../../gbdk/bin/lcc -Wa-l -Wl-m -Wl-j

BINS = chainsMatsu.gb

all:  $(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> compile.bat
	

%.gb:	../main.c
	$(CC) -o $@ $<

clean:
		rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi
