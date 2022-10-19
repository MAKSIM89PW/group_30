CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

all: Graph

Graph: graph.o calc.o stack.o drawPlot.o prefixN.o
	$(CC) -o ../build/Graph *.o	

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c

calc.o : calc.c
	$(CC) $(CFLAGS) calc.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

drawPlot.o: drawPlot.c
	$(CC) $(CFLAGS) drawPlot.c

prefixN.o : prefixN.c
	$(CC) $(CFLAGS) prefixN.c

clean:
	rm -rf *.o ../build/Graph

rebuild: clean all