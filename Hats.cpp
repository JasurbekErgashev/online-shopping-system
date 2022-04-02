
#include "Hats.h"

Hats::Hats(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& brands, const vector<int>& brandPrizes)
	: Clothes(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setBrands(brands);
	setBrandPrizes(brandPrizes);
}

void Hats::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Hats::getSubcategoryName() const {
	return subcategoryName;
}

void Hats::setBrands(const vector<string>& brands) {
	this->brands = brands;
}
vector<string> Hats::getBrands() const {
	return brands;
}

void Hats::setBrandPrizes(const vector<int>& brandPrizes) {
	int counter{ 0 };
	for (int i{ 0 }; i < brandPrizes.size(); i++) {
		if (brandPrizes[i] < 0) {
			counter++;
		}
	}
	if (counter == 0) {
		this->brandPrizes = brandPrizes;
	}
}
vector<int> Hats::getBrandPrizes() const {
	return brandPrizes;
}
