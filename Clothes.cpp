#include "CLothes.h"

Clothes::Clothes(const string& customerName, const double& customerBudget, const string& CategoryName)
	: Shopping(customerName, customerBudget) {
	setCategoryName(CategoryName);
}

void Clothes::setCategoryName(const string& CategoryName) {
	this->CategoryName = CategoryName;
}

string Clothes::getCategoryName() const {
	return CategoryName;
}

void Clothes::display() const {
	Shopping::display();
	cout << "Category name: " << getCategoryName() << endl;
}