#Compilation flags
CFLAGS = -Wall -o

#C files
CFILES = main.c utils.c

#Executable name
EXE = matrixMultiplier

multiplier:
	gcc $(CFLAGS) $(EXE) $(CFILES)
