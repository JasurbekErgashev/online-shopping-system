
#include "Fruits.h"

Fruits::Fruits(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& types, const vector<float>& typePrizes)
	: Food(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setTypes(types);
	setTypePrizes(typePrizes);
}

void Fruits::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Fruits::getSubcategoryName() const {
	return subcategoryName;
}

void Fruits::setTypes(const vector<string>& types) {
	this->types = types;
}
vector<string> Fruits::getTypes() const {
	return types;
}

void Fruits::setTypePrizes(const vector<float>& typePrizes) {
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
vector<float> Fruits::getTypePrizes() const {
	return typePrizes;
}

