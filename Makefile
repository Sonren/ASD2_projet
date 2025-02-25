CC = g++
CFLAGS=-Wall -std=c++17 -g
INCLUDES = -I.
LFLAGS = -lm
OBJ = main.o Personne.o Espace.o Election.o Electeur.o TableDeDecharge.o TableDeVote.o Isoloir.o
TARGET = main

all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)


main.o: main.cpp Personne.hpp Espace.hpp Election.hpp Electeur.hpp TableDeDecharge.hpp TableDeVote.hpp Isoloir.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp -o main.o

Personne.o: Personne.cpp Personne.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Personne.cpp -o Personne.o

Espace.o: Espace.cpp Espace.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Espace.cpp -o Espace.o

Election.o: Election.cpp Election.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Election.cpp -o Election.o

Isoloir.o: Isoloir.cpp Isoloir.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Isoloir.cpp -o Isoloir.o

Bulletin.o: Bulletin.cpp Bulletin.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Bulletin.cpp -o Bulletin.o

TableDeDecharge.o: TableDeDecharge.cpp TableDeDecharge.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c TableDeDecharge.cpp -o TableDeDecharge.o

TableDeVote.o: TableDeVote.cpp TableDeVote.hpp
	$(CC) $(CFLAGS) $(INCLUDES) -c TableDeVote.cpp -o TableDeVote.o

clean:
	rm -f *~ *.o main

