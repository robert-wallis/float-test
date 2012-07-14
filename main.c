#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>

#define DATA_COUNT 10000000

void usage(char** argv) {
	printf("usage: %s [data filename]\n", argv[0]);
}

float* load_data(char* filename);
float sum_square(float* X, int x_length);

int main(int argc, char** argv) {
	int i;
	float result;
	float x, theta;
	struct timeb start, end;
	if (argc < 2) {
		usage(argv);
		return -1;
	}
	float* data = load_data(argv[1]);	
	if (!data) {
		printf("error: couldn't load data\n");
		return -1;
	}
	printf("Loaded %d floats from %s\n", DATA_COUNT, argv[1]);
	result = sum_square(data, DATA_COUNT);
	printf("result %f\n", result);
	free(data);
	return 0;
}

float* load_data(char* filename) {
	int i;
	float* result;
	FILE* stream;
	stream = fopen(filename, "rb");
	if (!stream)
		return 0;
	result = malloc(DATA_COUNT * sizeof(float));
	for (i = 0; i < DATA_COUNT; i += 10000) {
		fread(result + i, 10000, sizeof(float), stream);
	}
	if (!result) {
		printf("unable to allocate %d floats in RAM\n", DATA_COUNT);
		return 0;
	}
	fclose(stream);
	return result;
}

// sum of the squares of X[i] * X[n-i]
float sum_square(float* X, int x_length) {
	int i;
	float result = 0.0f, x, theta;
	for(i = 0; i < x_length; i++) {
		x = X[i];
		theta = X[x_length-(i+1)];
		result += powf(x * theta, 2.0f);
	}
	return result;
}
