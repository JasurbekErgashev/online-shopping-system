
#include "Laptops.h"

Laptops::Laptops(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& models, const vector<int>& modelPrizes)
    : Electronics(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setModels(models);
	setModelPrizes(modelPrizes);
}

void Laptops::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Laptops::getSubcategoryName() const {
	return subcategoryName;
}

void Laptops::setModels(const vector<string>& models) {
	this->models = models;
}
vector<string> Laptops::getModels() const{
	return models;
}

void Laptops::setModelPrizes(const vector<int>& modelPrizes) {
	int counter{ 0 };
	for (int i{ 0 }; i < modelPrizes.size(); i++) {
		if (modelPrizes[i] < 0) {
			counter++;
		}
	}
	if (counter == 0) {
		this->modelPrizes = modelPrizes;
	}
}
vector<int> Laptops::getModelPrizes() const {
	return modelPrizes;
}

