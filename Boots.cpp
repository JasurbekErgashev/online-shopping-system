
#include "Boots.h"

Boots::Boots(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& brands, const vector<int>& brandPrizes)
	: Clothes(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setBrands(brands);
	setBrandPrizes(brandPrizes);
}

void Boots::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Boots::getSubcategoryName() const {
	return subcategoryName;
}

void Boots::setBrands(const vector<string>& brands) {
	this->brands = brands;
}
vector<string> Boots::getBrands() const {
	return brands;
}

void Boots::setBrandPrizes(const vector<int>& brandPrizes) {
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
vector<int> Boots::getBrandPrizes() const {
	return brandPrizes;
}
