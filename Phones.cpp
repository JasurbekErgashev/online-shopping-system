
#include "Phones.h"

Phones::Phones(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& models, const vector<int>& modelPrizes)
	: Electronics(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setModels(models);
	setModelPrizes(modelPrizes);
}

void Phones::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Phones::getSubcategoryName() const {
	return subcategoryName;
}

void Phones::setModels(const vector<string>& models) {
	this->models = models;
}
vector<string> Phones::getModels() const {
	return models;
}

void Phones::setModelPrizes(const vector<int>& modelPrizes) {
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
vector<int> Phones::getModelPrizes() const {
	return modelPrizes;
}
