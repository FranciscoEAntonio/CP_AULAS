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
		
		//buffer->__x = b;	
		if( (a*a + b*b) <= 1){
			(*count)++;
		}	
	}
	printf("hits no f: %i\n", *count);
	return (void*)count;
}

int main (int argc, char *argv[]) 
{

	int shots = atoi(argv[1]);	
	int* hits;
	if(argc > 2){
		int threads = atoi( argv[2]);
		pthread_t thread[threads];
		for(int i = 0; i < threads; i++){
			pthread_create(&thread[i], NULL, f, (void *) &shots);
		}
		for(int j = 0; j < threads; j++){
			pthread_join(thread[j], (void *) hits);
		}

	}else{
		*hits = *(int*)f((void*)&shots);
	}
printf("tou aqui\n");	
	printf("hits na main: %d\n", *hits);
printf("tou aqui2\n");	
	printf("%f\n", (double)(*hits*4)/shots);
printf("tou aqui3\n");	
	return 0;
}
