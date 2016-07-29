all: kilo

kilo: kilo.c
	$(CC) -o hecto kilo.c hecto/hecto.c -Wall -W -pedantic -std=c99

clean:
	rm kilo
