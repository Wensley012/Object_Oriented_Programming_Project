#pragma once
#include "Pizza.h"
class PizzaPersonalisee : public Pizza
{
	public:
		PizzaPersonalisee(const std::string& nom, double prixbase);

		double calculerPrix() const override;
		void afficherFacture() const override;
};

