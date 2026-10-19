#include "PizzaPersonalisee.h"
using namespace std;

PizzaPersonalisee::PizzaPersonalisee(const std::string& nom, double prixBase)
	:Pizza(nom, prixBase)
{
}

double PizzaPersonalisee::calculerPrix() const

{
    double total = prixBase;
    for (const Ingredient* ing : ingredients) {
        total += ing->getPrix();
    }
    return total;
}


void PizzaPersonalisee::afficherFacture() const
{
	cout << "\n[PIZZA PERSONNALISEE]\n";
	Pizza::afficherFacture();
}
