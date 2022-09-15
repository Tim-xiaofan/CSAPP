long = y

CFLAGS = -Wall

ifeq ($(long),y)
  CFLAGS += -m64 
else
  CFLAGS += -m32 
endif

main:main.c
	gcc $(CFLAGS) main.c -o main

clean:
	rm -f main
