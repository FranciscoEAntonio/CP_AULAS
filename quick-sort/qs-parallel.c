#include "qs-parallel.h"
#define TYPE double
#include <stdio.h>
#include <stdlib.h>


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
	for(int j = 0; j < nel - 2; j++){
		if(compar((void*)&arr[j], (void*)&arr[nel - 1]) < 0){
			i++;
			if(i != j)
				swap(arr, i, j);
		}
	}
	if(i > -1)
		swap(arr, i+1, nel-1);


	for(int i = 0; i < nel; i++)
		printf("%f ", arr[i]);
	printf("\n");
}
