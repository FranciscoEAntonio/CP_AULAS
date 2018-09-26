#include <stdlib.h>  
#include <drand48_r_libgw32c.h>

int main (int argc, char *argv[]) 
{

	int shots = (int) argv[1];
	if(argc > 2){
		int threads = (int) argv[2];
		pthread_t th2;
		pthread_create(&th2, NULL, f, (void *) &shots)
	}else{
		double res = f(&shots)
	}

	printf("%f\n", res*4);
	return 0;
}

void *f(void * arg){

	int * count = malloc(sizeof(int*));
	
	int y = *(int*)arg;

	double a = 0, b = 0;
	struct drand48_data *buffer;
	
	for(int i = 0; i < y; i++){
		drand48_r(buffer, a);
		drand48_r(buffer, b);
		
		if( (a*a + b*b) < 1){
			(*count)++;
		}	
	}

	return (void*)count;
}
