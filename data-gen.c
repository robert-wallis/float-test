#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DATA_COUNT 10000000

int main(int argc, char** argv) {
	int i;
	float a;
	FILE *stream;
	
	if (argc < 2) {
		printf("usage %s [output filename]\n", argv[0]);
		return -1;
	}
	srand(time(0));
	stream = fopen(argv[1], "w+");
	if (!stream)
		return -1;	
	for (i = 0; i < DATA_COUNT; i++) {
		a = (float)rand() / (float)RAND_MAX;
		fwrite(&a, sizeof(float), 1, stream);
		if (i % 100000 == 0) {
			printf("done writing %d random floats\n", i);
		}
	}
	fclose(stream);
	return 0;
}
