
#ifndef FRUITS
#define FRUITS

#include "Food.h"

class Fruits : public Food {
public:
	Fruits(const string & = "", const double& = 0.0, const string & = "", const string & = "", const vector<string> & = {}, const vector<float> & = {});

	void setSubcategoryName(const string&);
	string getSubcategoryName() const;

	void setTypes(const vector<string>&);
	vector<string> getTypes() const;

	void setTypePrizes(const vector<float>&);
	vector<float> getTypePrizes() const;

private:
	string subcategoryName;
	vector<string> types;
	vector<float> typePrizes;
};

#endif // !FRUITS
