#include <iostream>
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

using namespace std;

int main()
{
    cout << "OK" << endl;

    Catalogue catalogue = Catalogue();
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

    const char* lyon = "Lyon"; // ne pas delete
    const char* bordeaux = "Bordeaux";
    catalogue.Rechercher(lyon, bordeaux);
    catalogue.AfficherResRecherche();

    cout << endl << endl << endl << endl;

    const char* paris = "Paris";
    catalogue.Rechercher(paris, lyon);
    catalogue.AfficherResRecherche();



    return 0;
}
