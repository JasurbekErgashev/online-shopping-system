
#ifndef FOOD
#define FOOD

#include "Shopping.h"

class Food : public Shopping {
public:
	Food(const string & = "", const double& = 0.0, const string & = "");
	virtual ~Food() = default;

	void setCategoryName(const string&);
	string getCategoryName() const;

	virtual void display() const override;

private:
	string CategoryName;
};

#endif // !FOOD