#include "array.h"
#include "list.h"
#include "maze.h"

elem_t* resize(elem_t* tab, int a, int b)
{
		//Si a et b ont le même nombre d'élément on a rien besoin de faire
		if (a == b) return tab;

		elem_t* tmp = new elem_t[b];


		int k = a < b ? a : b; // min(a,b)
		//est-ce que a est plus petit que b ? si oui, k =a sinon k= b
		// revient au même que faire

		//if (a < b)
		//		k = a;
		//else
		//		k = b;
		for (int i = 0; i < k; i++)
				//k étant le plus petit des deux, ont ne veut pas dépasser sa taille
		{
				tmp[i] = tab[i];
		}
		if (tab != nullptr) delete tab;
		tab = tmp;
		return tab;
}

void reserve(array& tab, uint n)
{
		const uint STEP = 100;
		tab.size = 0;
		tab.capacity = n;
		tab.step = STEP;
		tab.data = n != 0 ? new elem_t[n] : nullptr;
}

void init(array& tab){
		reserve(tab, 0);
}
void push_back(array& tab, elem_t m)
{
		//Si ma taille est pareille a ma capacité
		if (tab.size == tab.capacity)
		{		//J'augmente ma capacité + le step
				tab.capacity += tab.step;
				tab.data = resize(tab.data, tab.capacity, tab.size);
		}
		tab.data[tab.size++] = m;

}

void shrink_to_fit(array& tab)
{
		if (tab.data != nullptr)
		{
				tab.data = resize(tab.data, tab.capacity, tab.size);
				tab.capacity = tab.size;
		}

}
void clear(array& tab)
{
		tab.size = 0;
		if (tab.data != nullptr)
				delete tab.data;
}

bool empty(array& tab)
{
		return tab.size == 0;

}

elem_t back(array& tab)
{
		return tab.data[tab.size - 1];
}


elem_t pop_back(array& tab)
{
		//Fonction qui retourne le dernier élément ajouté du tableau et le place dans n
		elem_t n = back(tab);

		if (tab.capacity - tab.size >= tab.step*1.5){
				tab.capacity -= tab.step;
				tab.data = resize(tab.data, tab.size, tab.capacity);
		}
		tab.size--;
		return n;
}