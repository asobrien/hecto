all: kilo

kilo: kilo.c
	$(CC) -o kilo kilo.c hecto/hecto.c -Wall -W -pedantic -std=c99

clean:
	rm kilo
