# default executable
defalut_mlib: normal_mlib

# minimal executable
minimal_mlib: ./Bool.h
	gcc -c ./Bool.h -o ./mlib.o

# normal executable
normal_mlib: ./Bool.h ./bytes.h
	gcc -c ./Bool.h ./bytes.h -o ./mlib.o 

# full executable
mlib: ./Bool.h ./bytes.h ./m_malloc.c ./str.c
	gcc -c ./Bool.h ./bytes.h ./m_malloc.c ./str.c -o ./mlib.o 

clean:
	rm *.o
