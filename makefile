# default executable
defalut_mlib: structure_mlib

# minimal math executable
minimal_math:	./m_math.c ./random.c
	@gcc -c -fPIC ./m_math.c -o ./m_math.o
	@echo "compiling ./m_math.c"
	@gcc -c -fPIC ./random.c -o ./random.o
	@echo "compiling ./random.c"
	@gcc -shared ./m_math.o ./random.o -o ./mlib.o
	@echo "done"

# full math executable
math_mlib: 		./vector.c ./m_math.c ./t_m_math.c ./s_m_math.c ./comp.c ./random.c
	@gcc -c -fPIC ./vector.c -o ./vector.o
	@echo "compiling ./vector.c"
	@gcc -c -fPIC ./m_math.c -o ./m_math.o
	@echo "compiling ./m_math.c"
	@gcc -c -fPIC ./t_m_math.c -o ./t_m_math.o
	@echo "compiling ./t_m_math.c"
	@gcc -c -fPIC ./s_m_math.c -o ./s_m_math.o
	@echo "compiling ./s_m_math.c"
	@gcc -c -fPIC ./comp.c -o ./comp.o
	@echo "compiling ./comp.c"
	@gcc -c -fPIC ./random.c -o ./random.o
	@echo "compiling ./random.c"
	@gcc -shared ./vector.o ./m_math.o ./t_m_math.o ./s_m_math.o ./comp.o ./random.o -o ./mlib.o
	@echo "done"

# string executable
strings_mlib: 	./m_malloc.c ./str.c ./fatstr.c
	@gcc -c -fPIC ./m_malloc.c -o ./m_malloc.o
	@echo "compiling ./vector.c"
	@gcc -c -fPIC ./str.c -o ./str.o
	@echo "compiling ./vector.c"
	@gcc -c -fPIC ./fatstr.c -o ./fatstr.o
	@echo "compiling ./vector.c"
	@gcc -shared ./m_malloc.o ./str.o ./fatstr.o -o ./mlib.o
	@echo "done"

# structure executable
structure_mlib: ./m_malloc.c ./fatstr.c ./vector.c ./comp.c ./nodes.c
	@gcc -c -fPIC ./m_malloc.c -o ./m_malloc.o
	@echo "compiling ./m_malloc.c"
	@gcc -c -fPIC ./fatstr.c -o ./fatstr.o
	@echo "compiling ./fatstr.c"
	@gcc -c -fPIC ./vector.c -o ./vector.o
	@echo "compiling ./vector.c"
	@gcc -c -fPIC ./comp.c -o ./comp.o
	@echo "compiling ./comp.c"
	@gcc -c -fPIC ./nodes.c -o ./nodes.o
	@echo "compiling ./nodes.c"
	@gcc -shared ./m_malloc.o ./fatstr.o ./vector.o ./comp.o ./nodes.o -o ./mlib.o
	@echo "done"

# full executable
mlib:	./m_malloc.c ./str.c ./fatstr.c ./vector.c ./m_math.c ./t_m_math.c ./s_m_math.c ./comp.c ./nodes.c ./random.c
	@gcc -c -fPIC ./m_malloc.c -o ./m_malloc.o
	@echo "compiling ./m_malloc.c"
	@gcc -c -fPIC ./str.c -o ./str.o
	@echo "compiling ./str.c"
	@gcc -c -fPIC ./fatstr.c -o ./fatstr.o
	@echo "compiling ./fatstr.c"
	@gcc -c -fPIC ./vector.c -o ./vector.o
	@echo "compiling ./vector.c"
	@gcc -c -fPIC ./m_math.c -o ./m_math.o
	@echo "compiling ./m_math.c"
	@gcc -c -fPIC ./t_m_math.c -o ./t_m_math.o
	@echo "compiling ./t_m_math.c"
	@gcc -c -fPIC ./s_m_math.c -o ./s_m_math.o
	@echo "compiling ./s_m_math.c"
	@gcc -c -fPIC ./comp.c -o ./comp.o
	@echo "compiling ./comp.c"
	@gcc -c -fPIC ./nodes.c -o ./nodes.o
	@echo "compiling ./nodes.c"
	@gcc -c -fPIC ./random.c -o ./random.o
	@echo "compiling ./random.c"
	@gcc -shared	./m_malloc.o ./str.o ./fatstr.o ./vector.o ./m_math.o ./t_m_math.o ./s_m_math.o ./comp.o ./nodes.o ./random.o -o ./mlib.o
	@echo "done"

clean:
	@rm *.o
	@echo "Cleaned"
