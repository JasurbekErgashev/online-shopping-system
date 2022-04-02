
#ifndef ELECTRONICS
#define ELECTRONICS

#include "Shopping.h"

class Electronics : public Shopping {
public:
	Electronics(const string & = "", const double& = 0.0, const string & = "");
	virtual ~Electronics() = default;

	void setCategoryName(const string&);
	string getCategoryName() const;

	virtual void display() const override;

private:
	string CategoryName;
};

#endif // !ELECTRONICS
