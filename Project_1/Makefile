
output:main.o LinkedList.o MainAnalyzer.o PrintHandler.o
	gcc main.o LinkedList.o MainAnalyzer.o PrintHandler.o -o output

main.o: main.c
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c

MainAnalyzer.o: MainAnalyzer.c MainAnalyzer.h
	gcc -c MainAnalyzer.c

PrintHandler.o: PrintHandler.c PrintHandler.h
	gcc -c PrintHandler.c

clean: 
	rm *.o output
