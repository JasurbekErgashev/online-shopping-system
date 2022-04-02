
#include "Vegetables.h"

Vegetables::Vegetables(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& types, const vector<float>& typePrizes)
	: Food(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setTypes(types);
	setTypePrizes(typePrizes);
}

void Vegetables::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Vegetables::getSubcategoryName() const {
	return subcategoryName;
}

void Vegetables::setTypes(const vector<string>& types) {
	this->types = types;
}
vector<string> Vegetables::getTypes() const {
	return types;
}

void Vegetables::setTypePrizes(const vector<float>& typePrizes) {
	int counter{ 0 };
	for (int i{ 0 }; i < typePrizes.size(); i++) {
		if (typePrizes[i] < 0) {
			counter++;
		}
	}
	if (counter == 0) {
		this->typePrizes = typePrizes;
	}
}
vector<float> Vegetables::getTypePrizes() const {
	return typePrizes;
}

