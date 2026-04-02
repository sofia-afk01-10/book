encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

message_h: message_hider.c encrypt.h 
	gcc -c message_hider.c

encrypt: encrypt.o message_hider.o
	gcc encrypt.o message_hider.o -o encrypt