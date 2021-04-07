TARGET=main
LD=gcc
OBJS=main.o queue.o 
FLAGS=-pthread 

all: $(OBJS)
	$(LD) $(FLAGS) $(OBJS) -o $(TARGET) && ./main

queue.o: queue.c
	$(LD) -c queue.c -o queue.o

main.o: main.c
	$(LD) -c main.c -o main.o

clean:
	rm -f *.o