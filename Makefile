
a.out: main.o ant.o field.o output.o
	$(CC) $^

main.o: ant.o field.o output.o
ant.o: 
field.o: ant.o
output.o: ant.o
