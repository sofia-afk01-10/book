# hfcal.o: hfcal.c
# 	gcc -c hfcal.c -o hfcal.o
# libhfsecurity.a: hfcal.o 
# 	ar -rcs libhfsecurity.a hfcal.o 
# elliptical: elliptical.c libhfsecurity.a
# 	gcc elliptical.c -L./my_lib -lhfsecurity -o elliptical

hfcal.o: hfcal_UK.c
	gcc -c -fPIC hfcal_UK.c -o hfcal.o

libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o my_lib/libhfcal.so

elliptical.o: elliptical.c
	gcc -I./include -c elliptical.c -o elliptical.o

elliptical: elliptical.o libhfcal.so
	gcc elliptical.o -L./my_lib -lhfcal -o elliptical