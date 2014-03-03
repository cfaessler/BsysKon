all: client server

client:
	gcc ../vorlagen/E25_clnt.c -o Aufgabe05_client.out

server:
	gcc Aufgabe05.c -o Aufgabe05_server.out -std=gnu99 -static -L../common -lserial

clean:
	rm -rf *o *.out
