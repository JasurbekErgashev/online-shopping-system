#include "Shopping.h"

Shopping::Shopping(const string& customerName, const double& customerBudget) {
	setCustomerName(customerName);
	setCustomerBudget(customerBudget);
}

void Shopping::setCustomerName(const string& customerName) {
	this->customerName = customerName;
}

void Shopping::setCustomerBudget(const double& customerBudget) {
	if (customerBudget >= 0.0) {
		this->customerBudget = customerBudget;
	}
}

string Shopping::getCustomerName() const {
	return customerName;
}

double Shopping::getCustomerBudget() const {
	return customerBudget;
}

void Shopping::display() const {
	cout << "Customer name: " << getCustomerName() << endl
		<< "Customer budget: " << getCustomerBudget() << endl;
}
