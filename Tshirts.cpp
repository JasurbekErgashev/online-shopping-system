
#include "Tshirts.h"

Tshirts::Tshirts(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& brands, const vector<int>& brandPrizes)
	: Clothes(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setBrands(brands);
	setBrandPrizes(brandPrizes);
}

void Tshirts::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Tshirts::getSubcategoryName() const {
	return subcategoryName;
}

void Tshirts::setBrands(const vector<string>& brands) {
	this->brands = brands;
}
vector<string> Tshirts::getBrands() const {
	return brands;
}

void Tshirts::setBrandPrizes(const vector<int>& brandPrizes) {
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
vector<int> Tshirts::getBrandPrizes() const {
	return brandPrizes;
}
