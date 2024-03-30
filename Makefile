CC = g++
CFLAGS=-Wall -std=c++17 -g
INCLUDES = -I.
LFLAGS = -lm
OBJ = main.o Personne.o FileAttente.o Espace.o Election.o
TARGET = main

all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)


main.o: main.cpp Personne.hpp FileAttente.hpp Espace.hpp Election.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp -o main.o

Personne.o: Personne.cpp Personne.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Personne.cpp -o Personne.o

FileAttente.o: FileAttente.cpp FileAttente.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c FileAttente.cpp -o FileAttente.o

Espace.o: Espace.cpp Espace.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Espace.cpp -o Espace.o

Election.o: Election.cpp Election.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Election.cpp -o Election.o

FileAttente.o: FileAttente.cpp FileAttente.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c FileAttente.cpp -o FileAttente.o

FileAttenteCapacite.o: FileAttenteCapacite.cpp FileAttenteCapacite.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c FileAttenteCapacite.cpp -o FileAttenteCapacite.o

Isoloir.o: Isoloir.cpp Isoloir.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Isoloir.cpp -o Isoloir.o

clean:
	rm -f *~ *.o main

