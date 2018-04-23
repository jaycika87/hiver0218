#include "array.h"
#include "list.h"
#include "maze.h"


void clear(list& list){
		node* n = list.front;
		while (n != nullptr){
				node* current = n;
				n = current->next;
				delete current;
		}
		list.back = nullptr;
		list.front = nullptr;
		list.size = 0;
}

bool empty(list& list){
		return list.size == 0;
}

void push_front(list& list, elem_t element){
		node*n = new node;
		n->element = element;
		n->previous = nullptr;
		n->next = list.front;
		if (list.front != nullptr) list.front->previous = n;
		list.front = n;
		if (list.back == nullptr) list.back = n;
		list.size++;
}

void push_back(list& list, elem_t element){
		node*n = new node;
		n->element = element;
		n->next = nullptr;
		n->previous = list.back;
		if (list.back != nullptr) list.back->next = n;
		list.back = n;
		if (list.front == nullptr) list.front = n;
		list.size++;


}

void erase(node*n){
		if (n == nullptr) return;
		if (n->previous != nullptr) n->previous->next = n->next;
		if (n->next != nullptr) n->next->previous = n->previous;
		delete n;
}

void erase2(list& list, node*n){
		if (n == list.front) list.front = list.front->next;
		if (n == list.back) list.back = list.back->previous;
		erase(n);
		list.size--;
}

elem_t pop_front(list& list){
		elem_t result = list.front->element;
		node* n = list.front->next;
		erase(list.front);
		list.front = n;
		list.size--;
		if (list.size == 0){
				list.back = nullptr;
				list.front = nullptr;
		}
		return result;
}

elem_t pop_back(list& list){
		elem_t result = list.back->element;
		node* n = list.back->previous;
		erase(list.back);
		list.back = n;
		list.size--;
		if (list.size == 0){
				list.back = nullptr;
				list.front = nullptr;
		}
		return result;
}

void insert(node* n, elem_t element){
		node* nn = new node;
		nn->element = element;
		nn->previous = n->previous;
		nn->next = n;
		if (n->previous != nullptr) n->previous->next = nn;
		n->previous = nn;
}

void insert2(list& list, node*n, elem_t element){
		insert(n, element);
		if (n == list.front) list.front = list.front->previous;
		list.size++;
}

void merge(node*n, list& list){
		if (empty(list)) return;

		node* previous = n->previous;
		n->previous = list.back;
		list.back->next = n;
		list.front->previous = previous;
		if (previous != nullptr){
				previous->next = list.front;
		}
}

void merge2(list& a, node*n, list& b){
		merge(n, b);
		a.size += b.size;
}