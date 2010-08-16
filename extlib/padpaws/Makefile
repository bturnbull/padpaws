
all: libpadpaws.so

libpadpaws.so: padpaws.o Makefile
	gcc -shared -W1,-sopadpaws,libpadpaws.so -o libpadpaws.so obj/padpaws.o

padpaws.o: Makefile
	mkdir -p obj
	gcc -Wall -fno-common -fPIC -Iinclude -o obj/padpaws.o -c src/padpaws.c 

clean:
	rm -rf obj
	rm -f libpadpaws.so
