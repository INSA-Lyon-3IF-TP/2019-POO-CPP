/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr / nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Afficher() const
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à la méthode Afficher de <Catalogue>" << endl;
#endif
    cout << "Affichage du Catalogue" << endl;
    for(unsigned i(0); i < tailleAct; ++i)
    {
      (*(mesTrajets)[i]).Afficher();
    }
    cout << "Fin de l'affichage du Catalogue" << endl;
} //----- Fin de Afficher

void Catalogue::AfficherResRecherche() const
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à la méthode AfficherResRecherche de <Catalogue>" << endl;
#endif
    cout << "Affichage du résultat de la recherche" << endl;
    for(unsigned i(0); i < tailleResRecherche; ++i)
    {
        (*(resultat)[i]).Afficher();
    }
    cout << "Fin de l'affichage du résultat de la recherche" << endl;
} //----- Fin de Afficher

void Catalogue::Ajouter(Trajet* trajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à la méthode Ajouter de <Catalogue>" << endl;
#endif
    if(tailleAct >= tailleMax)
    {
        this->Ajuster();
    }
    mesTrajets[tailleAct] = trajet;
    ++tailleAct;
} //----- Fin de Ajouter

void Catalogue::Rechercher(char* villeDep_, char* villeArr_)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à Rechercher() de <Catalogue>" << endl;
#endif
    tailleResRecherche = 0;
    for(unsigned i(0); i < tailleAct; ++i)
    {
        // cout << mesTrajets[i]->getVilleDep() << endl << mesTrajets[i]->getVilleArr() << endl;
        if(strcmp(mesTrajets[i]->getVilleDep(), villeDep_) == 0)
        {
            if(strcmp(mesTrajets[i]->getVilleArr(), villeArr_) == 0)
            {
                resultat[tailleResRecherche] = mesTrajets[i];
                ++tailleResRecherche;
            }
        }
    }
}


//------------------------------------------------- Surcharge d'opérateurs
//Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
//#endif
//} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue (unsigned tailleMax_)
    : tailleAct(0), tailleMax(tailleMax_)
    // Algorithme :
    //
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    mesTrajets = new Trajet*[tailleMax];
    resultat = new Trajet*[TAILLE_MAX_RECHERCHE];
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    for(unsigned i(0); i < tailleAct; ++i)
    {
        delete *(mesTrajets + i);
    }
    delete [] mesTrajets;
    delete [] resultat;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Méthodes privées

void Catalogue::Ajuster()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à la méthode Ajuster de <Catalogue>" << endl;
#endif
    tailleMax *= 2;
    Trajet** newTrajets = new Trajet*[tailleMax];
    for(unsigned i(0); i < tailleAct; ++i)
    {
        *newTrajets[i] = *mesTrajets[i];
    }
    delete [] *mesTrajets;
    *mesTrajets = *newTrajets;


} //----- Fin de Ajuster
