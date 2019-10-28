/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : 23/10/2019
    copyright            : (C) 2019 par Nicolas TROUIN
    e-mail               : nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


void Ensemble::Afficher(void)
{

	cout << cardAct << "\r\n";
	cout << cardMax << "\r\n";

	quickSort(this->elements, 0, cardAct-1);
	
	cout << "{";
	
	for(unsigned i(0); i < this->cardAct; ++i)
	{
		cout << this->elements[i];
		if(i < this->cardAct -1)
		{
			cout << ",";
		}
	}

	cout << "}\r\n";
}//Ensemble::Afficher()


bool Ensemble::EstEgal(const Ensemble & unEnsemble) const
{
	if(this->cardAct != unEnsemble.cardAct)
	{
		return false;
	}
	for(unsigned i(0); i < cardAct; ++i)
	{
		int current = this->elements[i];
		bool isPresent = false;
		for(unsigned j(0); j < cardAct; ++j)
		{
			if(current ==  unEnsemble.elements[j])
			{
				isPresent = true;
				break;
			}
		}
		if(!isPresent)
		{
			return false;
		}
	}
	return true;
}//Ensemble::EstEgal()

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const
{
	if(this->EstEgal(unEnsemble))
	{
		return INCLUSION_LARGE;
	}
	for(unsigned i(0); i < cardAct; ++i) //Parcours de this->elements[]
	{
		int current = this->elements[i];
		bool isPresent = false;
		for(unsigned j(0); j < unEnsemble.cardAct; ++j) //Parcours de unEnsemble.elements[]
		{
			if(current ==  unEnsemble.elements[j])
			{
				isPresent = true;
				break;
			}
		}
		if(!isPresent)
		{
			return NON_INCLUSION;
		}
	}
	return INCLUSION_STRICTE;	
}//Ensemble::EstInclus()


crduAjouter Ensemble::Ajouter(int aAjouter)
{
	for(unsigned i(0); i < cardAct; ++i) //Parcours de this->elements[]
	{
		int current = this->elements[i];
		if(current == aAjouter)
		{
			return DEJA_PRESENT;
		}
	}
	if(cardAct == cardMax)
	{
		return PLEIN;
	}
	this->elements[cardAct] = aAjouter;
	++cardAct;
	return AJOUTE;	
}//Ensemble::Ajouter()

unsigned int Ensemble::Ajuster(int delta)
{
	if(delta == 0)
	{
		return cardMax;
	}
	int minDelta = cardAct - cardMax;
	if(delta < minDelta)
	{
		cardMax = cardAct;
	}
	else
	{
		cardMax += delta;
	}
	int* tab = new int[cardMax];
	for(unsigned i(0); i < cardAct; ++i)
	{
		tab[i] = this->elements[i];
	}
	delete this->elements;
	this->elements = tab;
	return cardMax;
}//Ensemble::Ajuster()

bool Ensemble::Retirer(int element)
{
	for(unsigned i(0); i < cardAct; ++i) //Parcours de this->elements[]
	{
		int current = this->elements[i];
		if(current == element)
		{
			this->elements[i] = this->elements[cardAct-1];
			--cardAct;
			this->Ajuster(cardAct-cardMax);
			return true;
		}
	}
	this->Ajuster(cardAct-cardMax);
	return false;	
	
}//Ensemble::Retirer()


/*
	unsigned int Retirer(const Ensemble & unEnsemble);
	int Reunir(const Ensemble & unEnsemble);
	unsigned int Intersection(const Ensemble & unEnsemble);
*/

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble(unsigned int pcardMax)
	:cardMax(pcardMax),cardAct(0)
// Algorithme :
//
{
 	#ifdef MAP
    	cout << "Appel au constructeur par défaut de <Ensemble>" << endl;
  	#endif
	if(cardMax != 0)
	{
		elements = new int[cardMax];
	}
	else
	{
		elements = NULL;
	}
}//----- Fin de Ensemble (constructeur par défaut)


Ensemble::Ensemble(int t[], unsigned int nbElements)
	:cardMax(nbElements)
{
 	#ifdef MAP
    		cout << "Appel au constructeur via tableau de <Ensemble>" << endl;
  	#endif
	if(cardMax != 0)
	{
		elements = new int[cardMax];
		int i(0);
		for(unsigned j(0); j < nbElements; ++j) //Parcours de t[]
		{
			bool isPresent = false;
			for(unsigned k(0); k < j ; ++k) //Parcours de elements[] jusqu'a la position j
			{
				if(elements[k] == t[j])
				{
					isPresent = true;
					break;
				}
			}
			if(!isPresent)
			{
				elements[i] = t[j];
				++i;
			}
		}
		cardAct = i;
	}
	else
	{
		elements = NULL;
		cardAct = 0;
	}
	
}//----- Fin de Ensemble (constructeur via tableau)

Ensemble::~Ensemble()
{
  #ifdef MAP
      cout << "Appel au destructeur de <Ensemble>" << endl;
  #endif
  delete [] this->elements;
} //----- Fin de Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
*/
void quickSort( int a[], int first, int last ) 
{
    int pivotElement;
 
    if(first < last)
    {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}
 
/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
*/
int pivot(int a[], int first, int last) 
{
    int  p = first;
    int pivotElement = a[first];
 
    for(int i = first+1 ; i <= last ; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement)
        {
            p++;
            swap(a[i], a[p]);
        }
    }
 
    swap(a[p], a[first]);
 
    return p;
}
 
 
/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
