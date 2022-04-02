#include "Electronics.h"

Electronics::Electronics(const string& customerName, const double& customerBudget, const string& CategoryName)
	: Shopping(customerName, customerBudget) {
	setCategoryName(CategoryName);
}

void Electronics::setCategoryName(const string& CategoryName) {
	this->CategoryName = CategoryName;
}

string Electronics::getCategoryName() const {
	return CategoryName;
}

void Electronics::display() const {
	Shopping::display();
	cout << "Category name: " << getCategoryName() << endl;
}