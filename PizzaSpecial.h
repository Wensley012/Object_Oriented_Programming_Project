#pragma once
#include "Pizza.h"

class PizzaSpecial : public Pizza
{
	public:
		PizzaSpecial(const std::string& nom, double prixbase);

		double calculerPrix() const override;
		void afficherFacture() const override;
};