#ifndef VECTOR_H
#define VECTOR_H

#define INIT_STORAGE_SIZE 5

typedef struct vector {
  void **items;
  int storageSize;
  int totalItems;
} vector;

void vec_init(vector *);
int vec_total(vector *);
static void vec_resize(vector *, int);
void vec_add(vector *, void *);
void vec_set(vector *, int, void *);
void *vec_get(vector *, int);
void vec_delete(vector *, int);
void vec_free(vector *);

#endif
