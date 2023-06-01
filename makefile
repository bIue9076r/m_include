# default executable
defalut_mlib: normal_mlib

# minimal executable
minimal_mlib:	./Bool.h
	gcc -shared	./Bool.h -o ./mlib.o

# normal executable
normal_mlib:	./Bool.h ./bytes.h
	gcc -shared	./Bool.h ./bytes.h -o ./mlib.o

# minimal math executable
minimal_math:	./Bool.h ./m_math.c ./random.c
	gcc -shared	./Bool.h ./m_math.c ./random.c -o ./mlib.o

# full math executable
math_mlib: 		./Bool.h ./vector.c ./m_math.c ./s_m_math.c ./comp.c ./random.c
	gcc -shared	./Bool.h ./vector.c ./m_math.c ./s_m_math.c ./comp.c ./random.c -o ./mlib.o

# string executable
strings_mlib: 	./Bool.h ./m_malloc.c ./str.c ./fatstr.c
	gcc -shared	./Bool.h ./m_malloc.c ./str.c ./fatstr.c -o ./mlib.o

# structure executable
structure_mlib:	./Bool.h ./bytes.h ./m_malloc.c ./fatstr.c ./vector.c ./comp.c ./nodes.c
	gcc -shared	./Bool.h ./bytes.h ./m_malloc.c ./fatstr.c ./vector.c ./comp.c ./nodes.c -o ./mlib.o

# full executable
mlib: 			./Bool.h ./bytes.h ./m_malloc.c ./str.c ./fatstr.c ./vector.c ./m_math.c ./s_m_math.c ./comp.c ./nodes.c ./random.c
	gcc -shared	./Bool.h ./bytes.h ./m_malloc.c ./str.c ./fatstr.c ./vector.c ./m_math.c ./s_m_math.c ./comp.c ./nodes.c ./random.c -o ./mlib.o

clean:
	rm *.o
