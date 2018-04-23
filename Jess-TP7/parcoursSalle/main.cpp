//Par: Jessica Boulianne
//Date: 06/10/2017
//Laboratoire #7
//Parcours de salle en profondeur ou en largeur


#include "array.h"
#include "list.h"
#include "maze.h"
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
		//**********************************************************************
		//                               PILE
		array tab;
		init(tab);

		//Avoir la premi�re salle
		room* entree = entrance();

		//Avoir le contenu de a salle
		char nom = getRoomId(entree);

		// Met la premi�re salle dans le dernier �l�ment du tableau
		//EMPILER
		push_back(tab, entree);

		cout << "Parcours en profondeur 'LIFO' / pile:" << endl;

		//Tant que la pile n'est pas vide 
		while (!empty(tab))
		{
				//D�piler (dernier �l�ment ajout�, premier sortie)
				room* noeud = pop_back(tab);
				char node = getRoomId(noeud);


				//Obtenir le nombre d'enfant de noeud 
				int nbenfant = getNumDoors(noeud);


				//Pour chaque enfant de noeud allant de la droite vers la gauche
				//EMPILER
				for (int n = 0; n < nbenfant; n++)
				{
						room* enfant = getRoomAtDoor(noeud, nbenfant - n - 1);
						nom = getRoomId(enfant);
						push_back(tab, enfant);
				}

				//Affiche � l'�cran
				cout << setw(2) << node;

		}
		//**********************************************************************
		//                               FILE

		list liste = { 0 };

		//Avoir la premi�re salle
		room* entree2 = entrance();

		//Avoir le contenu de a salle
		nom = getRoomId(entree2);

		// Met la premi�re salle dans le dernier �l�ment du tableau
		//ENFILER
		push_back(liste, entree2);

		cout << endl << endl << "Parcours en largeur 'FIFO' / file:" << endl;

		//Tant que la file n'est pas vide 
		while (!empty(liste))
		{
				//D�filer (premier �l�ment ajout�, premier sortie)
				room* noeud = pop_front(liste);
				char node = getRoomId(noeud);

				//Obtenir le nombre d'enfant de noeud 
				int nbenfant = getNumDoors(noeud);


				//Pour chaque enfant de noeud allant de la gauche vers la droite
				//ENFILER
				for (int n = 0; n < nbenfant; n++)
				{
						room* enfant = getRoomAtDoor(noeud, n);
						nom = getRoomId(enfant);
						push_back(liste, enfant);
				}

				//Affiche � l'�cran
				cout << setw(2) << node;

		}
		cout << endl << endl;
		system("pause");
}