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
	printf("y: %i\n", y);
	for(int i = 0; i < y; i++){
		
		drand48_r(&buffer, &a);
		drand48_r(&buffer, &b);
		if( (a*a + b*b) <= 1){
			(*count)++;
		}	
	}
	printf("hits: %i\n", *count);
	return (void*)count;
}

int main (int argc, char *argv[]) 
{

	int shots = atoi(argv[1]);	
	int hits;
	if(argc > 2){
		int threads = *(int*) argv[2];
		pthread_t th2;
		pthread_create(&th2, NULL, f, (void *) &shots);

		pthread_join(th2, (void*)&hits);
	}else{
		hits = *(int*)f((void*)&shots);
	}
	
	printf("hits: %i\n", hits);
	printf("%f\n", (double)(hits*4)/shots);
	return 0;
}
