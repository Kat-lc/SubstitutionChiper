cipher: p2.o functions.o
	gcc -o cipher p2.o functions.o
p2.o:	p2.c functions.h
	gcc -c p2.c
functions.o: functions.h functions.c
	gcc -c functions.c
test:	encrypt decrypt compare
encrypt:
	./cipher e FEATHER datap.txt cipher.txt
decrypt:
	./cipher d FEATHER cipher.txt rdata.txt
compare:
	diff -s datap.txt rdata.txt
