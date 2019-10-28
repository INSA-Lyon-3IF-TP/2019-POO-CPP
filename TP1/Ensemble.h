/*************************************************************************
                             Ensemble  -  description
                             -------------------
    début                : 23/10/2019
    copyright            : (C) 2019 par Nicolas TROUIN
    e-mail               : nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#ifndef ENSEMBLE_H
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

const unsigned int CARD_MAX = 5;

//------------------------------------------------------------------ Types

enum crduEstInclus
{
	NON_INCLUSION,
	INCLUSION_LARGE,
	INCLUSION_STRICTE
};

enum crduAjouter
{
	DEJA_PRESENT,
	PLEIN,
	AJOUTE
};

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Afficher(void);
	bool EstEgal(const Ensemble & unEnsemble) const;
	crduEstInclus EstInclus(const Ensemble & unEnsemble) const;
	crduAjouter Ajouter(int aAjouter);
	unsigned int Ajuster(int delta);
	bool Retirer(int element);
	unsigned int Retirer(const Ensemble & unEnsemble);
	int Reunir(const Ensemble & unEnsemble);
	unsigned int Intersection(const Ensemble & unEnsemble); 


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
  
  Ensemble(unsigned int cardMax = CARD_MAX);
	Ensemble(int t[], unsigned int nbElements);
	virtual ~Ensemble();

//------------------------------------------------------------------ PRIVE
private :
unsigned int cardMax;
unsigned int cardAct;
int *elements;

protected:

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
/*
unsigned int cardMax;
unsigned int cardAct;
int *elements;
*/
};//class Ensemble

//-------------------------------- Autres définitions dépendantes de <Ensemble>

void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);

#endif // ENSEMBLE_H
