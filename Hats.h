
#ifndef HATS
#define HATS

#include "Clothes.h"

class Hats : public Clothes {
public:
    Hats(const string & = "", const double& = 0.0, const string & = "", const string & = "", const vector<string> & = {}, const vector<int> & = {});

    void setSubcategoryName(const string&);
    string getSubcategoryName() const;

    void setBrands(const vector<string>&);
    vector<string> getBrands() const;

    void setBrandPrizes(const vector<int>&);
    vector<int> getBrandPrizes() const;

private:
    string subcategoryName;
    vector<string> brands;
    vector<int> brandPrizes;
};

#endif // !HATS