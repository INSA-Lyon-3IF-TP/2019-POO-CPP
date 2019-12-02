/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

const char *Trajet::getVilleDep() const
{
#ifdef MAP
    cout << "Appel à getVilleDep() de <Trajet>" << endl;
#endif
    return villeDep;
}

const char *Trajet::getVilleArr() const
{
#ifdef MAP
    cout << "Appel à getVilleArr() de <Trajet>" << endl;
#endif
    return villeArr;
}


//-------------------------------------------- Constructeurs - destructeur
//Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
//#endif
//} //----- Fin de Xxx (constructeur de copie)

Trajet::Trajet (const char* uneVilleDep, const char* uneVilleArr )
    :villeDep(uneVilleDep),villeArr(uneVilleArr)
    // Algorithme :
    //
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete [] villeDep;
    delete [] villeArr;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
