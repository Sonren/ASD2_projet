CC = g++
CFLAGS=-Wall -std=c++17 -g
INCLUDES = -I.
LFLAGS = -lm
OBJ = main.o Personne.o FileAttente.o Espace.o
TARGET = main

all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)


main.o: main.cpp Personne.hpp FileAttente.hpp Espace.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp -o main.o

Personne.o: Personne.cpp Personne.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Personne.cpp -o Personne.o

Matrice.o: FileAttente.cpp FileAttente.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c FileAttente.cpp -o FileAttente.o

Vecteur.o: Espace.cpp Espace.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Espace.cpp -o Espace.o


clean:
	rm -f *~ *.o main

