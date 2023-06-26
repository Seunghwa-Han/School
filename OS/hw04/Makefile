CC = gcc
mm_main : mm_main.c mm.o
	$(CC) -o $@ $^
mm.o : mm.c mm.h
	$(CC) -c mm.c 
clean:
	rm *.o mm_main
