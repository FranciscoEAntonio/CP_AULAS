#include <stdlib.h>  
#include <stdio.h> 
#define _GNU_SOURCE
#include <pthread.h>
#include <time.h>

void *f(void * arg){

	int * count = malloc(sizeof(int*));
	*count = 0;
	register int y = *(int*)arg;
	long ms;
	double a = 0;
	double b = 0;
	//struct drand48_data buffer;
	//srand((unsigned) time(&t));
 	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);
	ms = spec.tv_nsec;
		
	for(register int i = 0; i < y; i++){
		
		//drand48_r(&buffer, &a);
		//drand48_r(&buffer, &b);
		a = (double)rand_r((unsigned int*)&ms)/RAND_MAX;
		b = (double)rand_r((unsigned int*)&ms)/RAND_MAX;
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
	int hits = 0;
	void * ret;
	if(argc > 2){
		int threads = atoi( argv[2]);
		int shotsPerThread = shots/threads;
		pthread_t thread[threads];
		for(int i = 0; i < threads; i++){
			pthread_create(&thread[i], NULL, f, (void *) &shotsPerThread);
		}
		for(int j = 0; j < threads; j++){
			pthread_join(thread[j], &ret);
			hits += *(int*)ret;
			free(ret);
		}
	}else{
		hits = *(int*)f((void*)&shots);
	}
	printf("hits na main: %d\n", hits);
	printf("%f\n", (double)(hits*4)/shots);
	return 0;
}
