#include <stdio.h>

int cmp(const void* a, const void* b){
	
}

size_t universalMax(const void *array, size_t len, size_t size_elem, int (*cmp)(const void*, const void*)){
	size_t index_max = 0;
	for (size_t i = 0; i < len; i++){
		if (cmp((array + index_max*size_elem), (array + i*size_elem)) < 0){
			index_max = i;
		}
	}
	return index_max;
}

int main(){

	return 0;
}
