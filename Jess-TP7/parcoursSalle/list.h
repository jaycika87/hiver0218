#pragma once
#include "maze.h"

//Déclaration d'un nouveau type qui est un pointeur room
using elem_t = room*;
using uint = unsigned int;

struct node {
		elem_t element;		// l'élément contenu dans le noeud
		node* next;			 // le noeud suivant
		node* previous;	// le noeud précédent
};

struct list{
		node* front;		      // le premier noeud de la liste
		node* back;			     // le dernier noeud de la liste
		uint size;	// le nombre d'éléments dans la liste
};


void clear(list& list);
bool empty(list& list);
void push_front(list& list, elem_t element);
void push_back(list& list, elem_t element);
void erase(node*n);
void erase2(list& list, node*n);
elem_t pop_front(list& list);
elem_t pop_back(list& list);
void insert(node* n, elem_t element);
void insert2(list& list, node*n, elem_t element);
void merge(node*n, list& list);
void merge2(list& a, node*n, list& b);
