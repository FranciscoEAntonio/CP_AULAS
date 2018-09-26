#include <stdlib.h>  
#include <stdio.h> 
#define _GNU_SOURCE
#include <pthread.h>


void *f(void * arg){

	int * count = malloc(sizeof(int*));
	
	int y = *(int*)arg;

	double a = 0;
	double b = 0;
	struct drand48_data buffer;
	
	for(int i = 0; i < y; i++){
		drand48_r(&buffer, &a);
		drand48_r(&buffer, &b);
		
		if( (a*a + b*b) < 1){
			(*count)++;
		}	
	}

	return (void*)count;
}

int main (int argc, char *argv[]) 
{

	int shots = *(int*) argv[1];
	double res;
	if(argc > 2){
		int threads = *(int*) argv[2];
		pthread_t th2;
		pthread_create(&th2, NULL, f, (void *) &shots);
	}else{
		res = *(double*)f((void*)&shots);
	}

	printf("%f\n", res*4);
	return 0;
}
