.PHONY:clean run

all: main.o src/test.o include/test.h
	gcc -I./ main.o src/test.o -o ./bin/test

main.o: main.c include/test.h
	gcc -I./ -c main.c

src/test.o: src/test.c include/test.h
	gcc -I./ -c src/test.c -o src/test.o

clean:
	rm -rf bin/test main.o src/test.o
run:
	./bin/test
