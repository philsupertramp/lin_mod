/**
 * File              : vector.h
 * Author            : Philipp Zettl <philipp.zettl@godesteem.de>
 * Date              : 28.09.2019
 * Last Modified Date: 28.09.2019
 * Last Modified By  : Philipp Zettl <philipp.zettl@godesteem.de>
 */
/**
 * lib/vector.h
 * Copyright (c) 2019 Philipp Zettl <philipp.zettl@godesteem.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VECTOR_H
#define VECTOR_H

#define INIT_STORAGE_SIZE 25

typedef struct vector {
  double **items;
  int storageSize;
  int totalItems;
} vector;

#define vector_t double

void vec_init(vector *);
int vec_total(vector *);
static void vec_resize(vector *, int);
void vec_add(vector *, double *);
void vec_set(vector *, int, double *);
double *vec_get(vector *, int);
void vec_delete(vector *, int);
void vec_free(vector *);

#endif
