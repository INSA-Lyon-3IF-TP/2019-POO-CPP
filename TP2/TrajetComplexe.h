/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.narboux@insa-lyon.fr & nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetComplexe> (fichier TrajetComplexe.h) ----------------
#if ! defined ( TRAJETCOMPLEXE_H )
#define TRAJETCOMPLEXE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComplexe>
//
//
//------------------------------------------------------------------------

class TrajetComplexe : public Trajet
{
//----------------------------------------------------------------- PUBLIC

  
public:
//----------------------------------------------------- Méthodes publiques
  static bool listeCorrect(Trajet* ppListeTrajets[],const unsigned nbElem,const char* vDep,const char*vArr);
  // Mode d'emploi (constructeur de copie) :
  //    Methode à appeler avant d'appeler le constructeur de TrajetComplexe !
  // Contrat :
  //    Retourne true si la liste de trajet est correctement ordonnée, false sinon

  virtual void Afficher() const;
  // Contrat :
  //    Permet d'afficher le trajet simple, doit être redéfinie par les classes filles

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
  // TrajetComplexe ( const TrajetComplexe & unTrajetComplexe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

  TrajetComplexe (Trajet* pplisteTrajets[], const unsigned fnbElem,const char* uneVilleDep,const char*uneVilleArr);
    // Mode d'emploi :
    //    Avant il faut appeler la methode listeCorrect et que la méthode est retournée TRUE 
    // Contrat :
    //    Affecte à m_ppTrajet une liste de pointeurs de trajets
  virtual ~TrajetComplexe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //    Détruit l'objet TrajetComplexe

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  unsigned nbElem = 0; // nombre de Trajets composant le trajet complexe
  Trajet** m_ppTrajet;
};

//-------------------------------- Autres définitions dépendantes de <TrajetComplexe>

#endif // TRAJETCOMPLEXE_H

