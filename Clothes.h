
#ifndef CLOTHES
#define CLOTHES

#include "Shopping.h"

class Clothes : public Shopping {
public:
	Clothes(const string & = "", const double& = 0.0, const string & = "");
	virtual ~Clothes() = default;

	void setCategoryName(const string&);
	string getCategoryName() const;

	virtual void display() const override;

private:
	string CategoryName;
};

#endif // !CLOTHES