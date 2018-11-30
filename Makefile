#use vpath to find source and header files in subdirectories
vpath %.c Polynomials
vpath %.h Polynomials

#assign variable CC to the gcc compiler
CC := gcc

#entry point of the make command
all: cleanModules run cleanMain

#command to run the executable after its compiled
run: Main
	@./Main

#main file
Main:  PolyTest.o PolyList.o Poly.o Main.c
	@$(CC) -Wall -ggdb -o $@ $^

#module twoD
Poly.o: Poly.c Poly.h
	@gcc -Wall -ggdb -c $<

PolyList.o: PolyList.c PolyList.h
	@gcc -Wall -ggdb -c $<

PolyTest.o: PolyTest.c
		@gcc -Wall -c -ggdb $<

#clean command "-f" to ignore messages when files don't exist
# using "@" to surpress the command being written out
cleanMain:
	@-rm -f Main *.o *~ *#

#command clean module folders to reduce
#messages after the executable has finished
cleanModules: PolyClean

#clean module folder
PolyClean:
	cd Polynomials
	@-rm -f *.o *~ *#
