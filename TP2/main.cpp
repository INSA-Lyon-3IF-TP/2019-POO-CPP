#include <iostream>
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

using namespace std;

void AjouterTrajet(Catalogue & catalogue);
void RechercherTrajet(Catalogue & catalogue);
void AfficherTrajet(Catalogue & catalogue);

int main()
{
  int commande = 0;
  Catalogue catalogue = Catalogue();
  cout << "Bienvenue dans ce simulateur de gesyion de transports." << endl << endl;
  while(commande != -1)
    {
      cout << "Menu :" << endl;
      cout << "-- (1) Ajouter un trajet au catalogue :" << endl;
      cout << "-- (2) Afficher le catalogue :" << endl;
      cout << "-- (3) Rechercher un parcours dans le catalogue :" << endl;
      cin >> commande;
      switch(commande)
	{
	case 1:
	  AjouterTrajet(catalogue);
	  break;
	case 2:
	  AfficherTrajet(catalogue);
	  break;
	case 3:
	  RechercherTrajet(catalogue);
	  break;
	case -1:
	  break;
	default:
	  cout << "Commande inconnue." << endl;
	  break;
	}
	}

  /*Catalogue catalogue = Catalogue();
    TrajetSimple* TS1 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::TRAIN); // A CHECK SANS LE NEW ET L'ETOILE
    TrajetSimple* TS2 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::AVION);
    TrajetSimple* TC3_1 = new TrajetSimple("Paris", "Marseille", MoyenTransport::AUTO);
    TrajetSimple* TC3_2 = new TrajetSimple("Marseille", "Lyon", MoyenTransport::BATEAU);
    const Trajet* liste[2] = {TC3_1, TC3_2};
    if(TrajetComplexe::listeCorrect(liste, 2, "Paris", "Lyon"))
    {
        TrajetComplexe* TC3 = new TrajetComplexe(liste, 2, "Paris", "Lyon");
        TC3->Afficher();
        catalogue.Ajouter(TC3);
    }
    catalogue.Ajouter(TS1);
    catalogue.Ajouter(TS2);



    //TS1->Afficher();
    catalogue.Afficher();

    cout << endl << endl << endl << endl;

    char* lyon = "Lyon"; // ne pas delete
    char* bordeaux = "Bordeaux";
    catalogue.Rechercher(lyon, bordeaux);
    catalogue.AfficherResRecherche();

    cout << endl << endl << endl << endl;

    char* paris = "Paris";
    catalogue.Rechercher(paris, lyon);
    catalogue.AfficherResRecherche();*/



    return 0;
}

void RechercherTrajet(Catalogue & catalogue)
{
  char villeDep[100],villeArr[100];
  cout << "Ville de départ : ";
  cin >> villeDep;
  cout << "Ville d'arrivée : ";
  cin >> villeArr;
  catalogue.Rechercher(villeDep,villeArr);
  cout << endl << "Résultat de la recherche :" <<endl;
  catalogue.AfficherResRecherche();
  cout << endl;
}

void AjouterTrajet(Catalogue & catalogue)
{
  TrajetSimple* TS1 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::TRAIN);
  TrajetSimple* TS2 = new TrajetSimple("Lyon", "Bordeaux", MoyenTransport::AVION);
  TrajetSimple* TC3_1 = new TrajetSimple("Paris", "Marseille", MoyenTransport::AUTO);
  TrajetSimple* TC3_2 = new TrajetSimple("Marseille", "Lyon", MoyenTransport::BATEAU);
  catalogue.Ajouter(TS1);
  catalogue.Ajouter(TS2);
  const Trajet* liste[2]; // = {TC3_1, TC3_2};
  liste[0] = TC3_1;
  liste[1] = TC3_2;
  if(TrajetComplexe::listeCorrect(liste, 2, "Paris", "Lyon"))
    {
      TrajetComplexe* TC3 = new TrajetComplexe(liste, 2, "Paris", "Lyon");
      catalogue.Ajouter(TC3);
    }
}

void AfficherTrajet(Catalogue & catalogue)
{
  catalogue.Afficher();
}
