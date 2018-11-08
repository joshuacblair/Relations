CC = g++
FLAGS = -ggdb -Wall -Werror -std=c++17 -fno-omit-frame-pointer
FILES = Source.cpp Relation.cpp
H_FILES = Relation.h

lab3: $(FILES) $(H_FILES)
	$(CC) $(FLAGS) $(FILES) -o lab3

clean:
	rm -f lab3
