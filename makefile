# Compile an executable named yourProgram from yourProgram.c
run: main.c
	gcc -g -Wall -o main main.c
	main.exe