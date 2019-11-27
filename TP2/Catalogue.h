/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2019
    copyright            : (C) 2019 par Fabien NARBOUX & Nicolas TROUIN
    e-mail               : fabien.naboux@insa-lyon.fr / nicolas.trouin@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes
const unsigned TAILLE_MAX = 5;
const unsigned TAILLE_MAX_RECHERCHE = 50;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AfficherResRecherche() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(Trajet* trajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Rechercher(const char* & villeDep_, const char* & villeArr_);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    //Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    //Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue (unsigned tailleMax_ = TAILLE_MAX);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

private:
    //----------------------------------------------------- Méthodes privées
    void Ajuster();
    // Mode d'emploi :
    //
    // Contrat :
    // Double la taille max du tableau (réallocation).

    //----------------------------------------------------- Attributs privés
    unsigned tailleAct;
    unsigned tailleMax;
    unsigned tailleResRecherche;
    Trajet** mesTrajets;
    Trajet** resultat;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

