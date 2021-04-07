TARGET=main
LD=gcc
OBJS=main.o queue.o threads.o

all: $(OBJS)
	$(LD) $(OBJS) -o $(TARGET) && ./main

queue.o: queue.c
	$(LD) -c queue.c -o queue.o

main.o: main.c
	$(LD) -c main.c -o main.o

threads.o: threads.c
	$(LD) -c threads.c -o threads.o

clean:
	rm -f *.o