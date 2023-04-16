CC = /Escritorio/Matsuori/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j

BINS = chainsMatsu.gb

all:  $(BINS)

%.gb: %.c
      $(CC) -o $@ $<

clean:
		rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi

