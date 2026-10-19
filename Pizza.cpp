#include "Pizza.h"                                                 
#include <format>
using namespace std;

Pizza::Pizza( const std::string& nom, double prixBase )
{
	this->nom = nom;
	this->prixBase = prixBase;
}

Pizza::~Pizza()
{
	for (size_t i = 0; i < this->ingredients.size(); i++)
	{
		delete this->ingredients[i];
	}

	this->ingredients.clear();

	cout <<"-> destruction des ingredients de la pizza"
		<< this->nom << "\n";
}

void Pizza::ajouterIngredient(Ingredient* ing)
{
	this->ingredients.push_back(ing);
}

Pizza& Pizza::operator+=(Ingredient* ing)
{
	this->ajouterIngredient(ing);
	return *this;
}

void Pizza::afficherFacture() const
{
	    cout << "--> " << this->nom
		<< " (Base : " << format("{:.2f}", this->prixBase) << " $)\n";
		cout << "    - Ingredients ajoutes : " << endl;
	for (const Ingredient* ing : ingredients) {
		cout << "      + " << ing->getNom()
			<< " (" << std::format("{:.2f}", ing->getPrix()) << " $)\n";
	}
}


std::ostream& operator<<(std::ostream& os, const Pizza& p)
{
	os << "--> " << p.nom
		<< " : " << format("{:.2f}", p.prixBase) << "$\n";
	
	os << "- Ingredients ajoutes : \n";

	for (size_t i = 0; i < p.ingredients.size(); i++)
	{
		os << "   " << *p.ingredients[i] << "\n";
	}

	return os;
}
