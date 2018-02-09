CC=gcc
CFLAGS=-Wall
EXEC=multmatrix

all: $(EXEC)

multmatrix: main.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o
	rm $(EXEC)

mrproper: clean
	rm -rf $(EXEC)
