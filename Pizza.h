#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <format>
#include "Ingredient.h"
class Pizza
{
	protected:
		std::string nom;
		double prixBase;
		std::vector<Ingredient*> ingredients;

	public:
		Pizza(const std::string& nom, double prixBase);
		virtual ~Pizza();

		void ajouterIngredient(Ingredient* ing);
		Pizza& operator+=(Ingredient* ing);

		virtual double calculerPrix() const = 0;
		virtual void afficherFacture() const;



		friend std::ostream& operator<<(std::ostream& os, const Pizza& p);

};

