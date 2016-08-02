all: kilo

kilo: kilo.c
	$(CC) -o hecto kilo.c hecto.c -Wall -W -pedantic -std=c99

clean:
	rm -f hecto
