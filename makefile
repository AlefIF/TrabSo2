TARGET=main
LD=gcc
OBJS=main.o queue.o

all: $(OBJS)
	$(LD) $(OBJS) -o $(TARGET) && (clear; ./$(TARGET))

queue.o: queue.c
	$(LD) -c queue.c -o queue.o

main.o: main.c
	$(LD) -c main.c -o main.o

clean:
	rm -f *.o