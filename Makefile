#use vpath to find source and header files in subdirectories
vpath %.c Polynomials:Hash_Tables
vpath %.h Polynomials:Hash_Tables

#assign variable CC to the gcc compiler
CC := gcc

#entry point of the make command
all: cleanModules run cleanMain 

#command to run the executable after its compiled
run: Main
	@./Main

#main file 
Main: Poly.o Hash.o Main.c
	@$(CC) -Wall -ggdb -o $@ $^

#module twoD
Poly.o: Poly.c Poly.h
	@gcc -Wall -ggdb -c $<

Hash.o: Hash.c Hash.h
	@gcc -Wall -ggdb -c $<

#clean command "-f" to ignore messages when files don't exist
# using "@" to surpress the command being written out
cleanMain:
	@-rm -f Main *.o *~ *#

#command clean module folders to reduce
#messages after the executable has finished
cleanModules: PolyClean HashClean

#clean module folder
PolyClean:
	cd Polynomials
	@-rm -f Poly *.o *~ *#

HashClean:
	cd Hash_Tables
	@-rm -f Hash *.o *~ *#
