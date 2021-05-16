libname=libtest.lib
ObjFileName=dish
$(ObjFileName):*.o
		rm main.o
		@echo rmmaino success
		@echo $(libname)
		ar rsc $(libname) *.o
		gcc main.c -o $(ObjFileName) -L ./ -l test
		rm *.o
*.o:*.c
	gcc -c *.c

