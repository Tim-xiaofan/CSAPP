hello:hello.o
	gcc hello.o -o hello
hello.o:hello.s
	gcc -c hello.s -o hello.o
hello.s:hello.i
	gcc -S hello.i -o hello.s
hello.i:hello.c
	gcc -E hello.c -o hello.i

clean:
	rm -f hello.o hello.s hello.i hello
