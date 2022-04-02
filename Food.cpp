#include "Food.h"

Food::Food(const string& customerName, const double& customerBudget, const string& CategoryName)
	: Shopping(customerName, customerBudget) {
	setCategoryName(CategoryName);
}

void Food::setCategoryName(const string& CategoryName) {
	this->CategoryName = CategoryName;
}

string Food::getCategoryName() const {
	return CategoryName;
}

void Food::display() const {
	Shopping::display();
	cout << "Category name: " << getCategoryName() << endl;
}