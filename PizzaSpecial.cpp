#include "PizzaSpecial.h"
using namespace std;

PizzaSpecial::PizzaSpecial(const string& nom, double prixBase)
	:Pizza(nom, prixBase)
{
}

double PizzaSpecial::calculerPrix() const
{
	
	double total = prixBase;
	for (const Ingredient* ing : ingredients) {
		total += ing->getPrix();
	}
	double rabais = total * 0.15;
	double newTotal = total - rabais;
	return newTotal;
}

void PizzaSpecial::afficherFacture() const
{
	cout << "\n[PIZZA SPECIAL EN PROMOTION]" << endl;
	Pizza::afficherFacture();
	PizzaSpecial::calculerPrix();
	cout << "    *** (Rabais de 15% applique sur le totale final) ***\n";
}
