#pragma once
#include <string>
#include <iostream>
class Ingredient
{
private:
		std::string nom;
		double prix;

public:
	Ingredient(const std::string& nom, double prix);

	std::string getNom() const;
	double getPrix() const;

	friend std::ostream& operator<<(std::ostream& os, const Ingredient& ing);
};