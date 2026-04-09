encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o
checksum.o: checksum.c	
	gcc -c checksum.c -o checksum.o
libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o
test_code: test_code.c libhfsecurity.a
	gcc test_code.c -L./my_lib -lhfsecurity -o test_code