
#include "Traditional.h"

Traditional::Traditional(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& types, const vector<float>& typePrizes)
	: Food(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setTypes(types);
	setTypePrizes(typePrizes);
}

void Traditional::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Traditional::getSubcategoryName() const {
	return subcategoryName;
}

void Traditional::setTypes(const vector<string>& types) {
	this->types = types;
}
vector<string> Traditional::getTypes() const {
	return types;
}

void Traditional::setTypePrizes(const vector<float>& typePrizes) {
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
vector<float> Traditional::getTypePrizes() const {
	return typePrizes;
}

