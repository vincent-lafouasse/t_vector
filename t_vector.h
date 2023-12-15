#ifndef T_VECTOR_H_
#define T_VECTOR_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct s_vector
{
	int* data;
	size_t len;
	size_t capacity;
} t_vector;

// Allocation/Destruction
t_vector* 	vector_new(void);
t_vector* 	vector_new_with_capacity(size_t capacity__);
t_vector* 	vector_new_with_capacity_with_value(size_t capacity__, int value);
t_vector* 	vector_new_from_array(int* array, size_t size);
void 		vector_delete(t_vector* v);

// Capacity management
void 		vector_resize(size_t capacity__);
void 		vector_shrink_to_fit(void);

// Mutators
void 		vector_push_back(t_vector* v, int value);
void 		vector_insert(t_vector* v, int value, size_t position);
void 		vector_push_front(t_vector* v, int value);

void 		vector_pop_back(t_vector* v);
void 		vector_pop_erase(t_vector* v, size_t position);
void 		vector_pop_front(t_vector* v);

// Accessors
int 		vector_at(t_vector* v, size_t position);
int 		vector_front(t_vector* v);
int 		vector_back(t_vector* v);

// Properties
bool 		vector_is_empty(t_vector* v);
bool 		vector_is_sorted(t_vector* v);

// Algorithms
void 		vector_sort(t_vector* v);
void 		vector_rotate(t_vector* v);

void 		vector_sort_with(t_vector* v, bool (*pred)(int a, int b));

#endif
