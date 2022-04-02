
#include "Televisions.h"

Televisions::Televisions(const string& customerName, const double& customerBudget, const string& CategoryName, const string& subcategoryName, const vector<string>& models, const vector<int>& modelPrizes)
	: Electronics(customerName, customerBudget, CategoryName) {
	setSubcategoryName(subcategoryName);
	setModels(models);
	setModelPrizes(modelPrizes);
}

void Televisions::setSubcategoryName(const string& subcategoryName) {
	this->subcategoryName = subcategoryName;
}

string Televisions::getSubcategoryName() const {
	return subcategoryName;
}

void Televisions::setModels(const vector<string>& models) {
	this->models = models;
}
vector<string> Televisions::getModels() const {
	return models;
}

void Televisions::setModelPrizes(const vector<int>& modelPrizes) {
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
vector<int> Televisions::getModelPrizes() const {
	return modelPrizes;
}

