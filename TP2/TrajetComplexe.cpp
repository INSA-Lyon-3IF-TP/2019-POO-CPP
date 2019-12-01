/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : 27/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetComplexe> (fichier TrajetComplexe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool TrajetComplexe::listeCorrect(const Trajet* ppListeTrajets[],const unsigned nbElem,const char* vDep,const char*vArr)
// Algorithme :
//
{
  const char* villeDepart;
  const char* villeArrivee;
  //if(nbElem<2) return true;
  villeDepart = ppListeTrajets[0]->getVilleDep();
  if(strcmp(villeDepart,vDep) != 0)
  {
      return false;
  }
  villeArrivee = ppListeTrajets[0]->getVilleArr();
  if(nbElem<2 && strcmp(villeArrivee,vArr) == 0)
  {
      return true;
  }
  else if(nbElem < 2 && strcmp(villeArrivee, vArr) != 0)
  {
      return false;
  }
  for(unsigned i = 1; i<nbElem; ++i)
    {
      if(strcmp(ppListeTrajets[i]->getVilleDep(),villeArrivee) != 0)
      {
          return false;
      }
      villeArrivee = ppListeTrajets[i]->getVilleArr();
    }
  if(strcmp(villeArrivee,vArr) != 0)
  {
      return false;
  }
  return true;
} //----- Fin de Méthode

void TrajetComplexe::Afficher() const
// Algorithme :
//
{
    for(unsigned i = 0; i<nbElem; ++i)
    {
        m_ppTrajet[i]->Afficher();
    }
} //------Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
//Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
//#endif
//} //----- Fin de Xxx (constructeur de copie)


TrajetComplexe::TrajetComplexe (const Trajet* pplisteTrajets[], const unsigned fnbElem,const char* uneVilleDep,const char*uneVilleArr)
  :Trajet(uneVilleDep,uneVilleArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComplexe>" << endl;
#endif
    m_ppTrajet = new Trajet*[fnbElem];
    for(unsigned i = 0; i<fnbElem ; ++i)
    {
        m_ppTrajet[i] = const_cast<Trajet*>(pplisteTrajets[i]);
    }
    nbElem = fnbElem;
} //----- Fin de TrajetComplexe


TrajetComplexe::~TrajetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComplexe>" << endl;
#endif
    for(unsigned i = 0; i<nbElem; ++i)
      {
        delete m_ppTrajet[i];
      }
    delete [] m_ppTrajet;
} //----- Fin de ~TrajetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

