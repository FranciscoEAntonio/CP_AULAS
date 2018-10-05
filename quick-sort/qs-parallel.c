#include "qs-parallel.h"
#define TYPE double


void swap(TYPE* arr, int i, int j){
	TYPE aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;	
}

void qsort_parallel(void *base, size_t nel, size_t width, 
                    int (*compar)(const void *, const void *)){

	/* Do your own parallel (Cilk+) implementation of Quick Sort */
	
	//sequencial
	TYPE* arr = (TYPE*) base;
	int i = -1;
	for(int j = 0; j < nel - 1; j++){
		if(compar((void*)&arr[j], (void*)&arr[nel - 1]) < 0){
			i++;
			swap(arr, i, j);
		}
	}
}
