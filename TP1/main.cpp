#include "Ensemble.h"

int main()
{
	int t[6] = {55,-97,-97,-97,-97,97};
	Ensemble e(t,6);
	e.Afficher();
	e.Retirer(97);
	e.Afficher();
	return 0;
}
