#pragma once
#include "maze.h"

using elem_t = room*;
using uint = unsigned int;

struct array
{
		elem_t* data;
		uint size;
		uint capacity;
		uint step;
};

elem_t* resize(elem_t* tab, int a, int b);
void reserve(array& tab, uint n);
void init(array& tab);
void push_back(array& tab, elem_t m);
void shrink_to_fit(array& tab);
void clear(array& tab);
bool empty(array& tab);
elem_t back(array& tab);
elem_t pop_back(array& tab);

