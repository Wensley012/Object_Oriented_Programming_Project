#include "Ingredient.h"
#include <format>
using namespace std;

Ingredient::Ingredient(const string& nom, double prix)
{
	this->nom = nom;
	this->prix = prix;
}

string Ingredient::getNom() const
{
	return this->nom;
}

double Ingredient::getPrix() const
{
	return this->prix;
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ing)
{
	os << ing.nom 
		<< " (" << format("{:.2f}", ing.prix) << "$)";
	return os;
}
