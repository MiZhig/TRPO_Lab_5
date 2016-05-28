INCLUDE=-I ./thirdparty
INCLUDE1=-I ./src

all: bin/main bin/test

bin/main: obj/main.o obj/proc.o
	mkdir bin
	gcc -o bin/main obj/main.o obj/proc.o -Wall -lm

bin/test: obj/proc_test.o obj/main_test.o
	gcc -o bin/test obj/main_test.o obj/proc_test.o obj/proc.o -Wall -lm

test:	bin/test
	./bin/test

obj/main.o: src/main.c
	mkdir obj
	gcc $(INCLUDE1) -c src/main.c -Wall -o obj/main.o

obj/proc.o: src/proc.c
	gcc $(INCLUDE1) -c src/proc.c -Wall -o obj/proc.o

obj/main_test.o: test/main_test.c
	gcc $(INCLUDE) -c test/main_test.c -Wall -o obj/main_test.o

obj/proc_test.o: test/proc_test.c
	gcc $(INCLUDE1) $(INCLUDE) -c test/proc_test.c -Wall -o obj/proc_test.o -lm

.PHONY: clean
clean:
	rm -f -r bin/ obj/
