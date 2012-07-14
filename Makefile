.PHONY: all test clean

all: fptest data-gen

fptest: main.o
	$(CC) -Wall -lm $^ -o $@

data-gen: data-gen.o
	$(CC) -Wall -lm $^ -o $@

clean:
	rm -f *.o fptest data-gen random.float

test: all
	./data-gen random.float	
	./fptest random.float
