
#ifndef SHOPPING_H
#define SHOPPING_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shopping {
public:
	Shopping(const string & = "", const double& = 0.0);
	virtual ~Shopping() = default;

	void setCustomerName(const string&);
	void setCustomerBudget(const double&);

	string getCustomerName() const;
	double getCustomerBudget() const;

	virtual void display() const;

private:
	string customerName;
	double customerBudget{ 0.0 };
};

#endif // !SHOPPING_H
