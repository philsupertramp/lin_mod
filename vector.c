#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vec_init(vector *vec){
  vec->storageSize = INIT_STORAGE_SIZE;
  vec->totalItems = 0;
  vec->items = malloc(sizeof(void*) * vec->storageSize); 
}
