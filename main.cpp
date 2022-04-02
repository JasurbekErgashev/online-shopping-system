#include <iomanip>
#include <algorithm>
#include "Windows.h"

#include "Shopping.h"
#include "Electronics.h"
#include "Food.h"
#include "Clothes.h"

#include "Laptops.h"
#include "Phones.h"
#include "Televisions.h"

#include "Fruits.h"
#include "Vegetables.h"
#include "Traditional.h"

#include "Boots.h"
#include "Hats.h"
#include "Tshirts.h"

void welcome(string name) {
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	for (int i{ 1 }; i <= 80; i++) {
		cout << "\x1B[32m*\033[0m";
	}
	for (int i{ 1 }; i <= 5; i++) {
		cout << endl;
		if (i == 3) {
			cout << "\x1B[31m*\033[0m";
			int textSize = 7 + name.size() + 20;
			int sizeInfo = 78 - textSize;
			int spaceSize{ 0 };
			if (sizeInfo % 2 == 1)
				spaceSize = sizeInfo / 2;
			else
				spaceSize = (sizeInfo - 2) / 2;
			for (int i{ 1 }; i <= spaceSize; i++) {
				cout << " ";
			}
			if ((78 - textSize) % 2 == 0)
				cout << "\x1B[36mWELCOME  \033[0m" << name << "\x1B[36m TO OUR ONLINE SHOP!\033[0m";
			else
				cout << "\x1B[36mWELCOME \033[0m" << name << "\x1B[36m TO OUR ONLINE SHOP!\033[0m";
			for (int i{ 1 }; i <= spaceSize; i++) {
				cout << " ";
			}
			cout << "\x1B[31m*\033[0m";
		}
		else {
			for (int i{ 1 }; i <= 80; i++) {
				if (i == 1 || i == 80 || i == 2 || i == 79)
					cout << "\x1B[35m*\033[0m";
				else
					cout << " ";
			}
		}
	}
	cout << endl;
	for (int i{ 1 }; i <= 80; i++) {
		cout << "\x1B[32m*\033[0m";
	}
	cout << endl;
}

// electronics functions
void laptopsCase(int, double*, Laptops, Electronics, Food, Clothes, vector<string>&, string, double);
void phonesCase(int, double*, Phones, Electronics, Food, Clothes, vector<string>&, string, double);
void televisionsCase(int, double*, Televisions, Electronics, Food, Clothes, vector<string>&, string, double);

// food functions
void fruitsCase(int, double*, Fruits, Electronics, Food, Clothes, vector<float>&, vector<string>&, string, double);
void vegetablesCase(int, double*, Vegetables, Electronics, Food, Clothes, vector<float>&, vector<string>&, string, double);
void traditionalCase(int, double*, Traditional, Electronics, Food, Clothes, vector<float>&, vector<string>&, string, double);

// clothes functions
void bootsCase(int, double*, Boots, Electronics, Food, Clothes, vector<string>&, string, double);
void tshirtsCase(int, double*, Tshirts, Electronics, Food, Clothes, vector<string>&, string, double);
void hatsCase(int, double*, Hats, Electronics, Food, Clothes, vector<string>&, string, double);

int main() {

	vector<string> purchasedElectronics = {};
	vector<string> purchasedFood = {};
	vector<float> purchasedFoodQuantities = {};
	vector<string> purchasedClothes = {};

	string name;
	cout << "Enter your name: ";
	cin >> name;
	static double budget;
	cout << "Enter your budget in $";
	cin >> budget;

	Shopping customerInfo{ name, budget };

	double initialBudget = budget;

	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl;

	cout << "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n";

	Electronics electronics{ name, budget, "ELECTRONICS" };
	Food food{ name, budget, "FOOD" };
	Clothes clothes{ name, budget, "CLOTHES" };

	const Electronics* electronicsPtr{ &electronics };
	const Food* foodPtr{ &food };
	const Clothes* clothesPtr{ &clothes };

	cout << "\x1B[36m1\033[0m." << electronicsPtr->getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << foodPtr->getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothesPtr->getCategoryName() << "\n\n";

	int index;
	cout << "Enter the index of category or -1 to quit: ";
	cin >> index;

	while (index != -1) {

		if (index == 1) {
			Laptops laptops{ name, budget, "ELECTRONICS", "Laptops", {"Apple MacBook Air", "HP Spectre x360", "Acer Swift 3", "Asus ZenBook 13", "Lenovo ThinkPad X1"}, {999, 1'999, 699, 799, 1'960} };
			Phones phones{ name, budget, "ELECTRONICS", "Phones", {"Google Pixel 6 Pro", "Apple iPhone 13 Pro", "Samsung Galaxy S22 Ultra", "Oppo Find X5 Pro", "Xiaomi 12 Pro"}, {1'099, 1'599, 1'299, 850, 796} };
			Televisions televisions{ name, budget, "ELECTRONICS", "TVs", {"LG C1 Oled", "Samsung QN90A QLED", "Sony A90J", "Vizio 2020", "Artel TV Led 9000"}, {753, 1'150, 800, 950, 0} };

			vector<string> ElectonicsSubCategories = { laptops.getSubcategoryName(), phones.getSubcategoryName(), televisions.getSubcategoryName() };

			cout << "\n";
			for (int i{ 0 }; i < ElectonicsSubCategories.size(); i++) {
				cout << i + 1 << ". " << ElectonicsSubCategories[i] << endl;
			}

			cout << "\nEnter the index of subcategory: ";
			int subIndex;
			cin >> subIndex;
			bool isTrue = true;
			while (isTrue) {
				if (subIndex == 1) {

					cout << "\n";
					for (int i{ 0 }; i < laptops.getModels().size(); i++) {
						cout << i + 1 << ". " << setw(18) << left << laptops.getModels()[i] << "   \x1B[36mPrice\033[0m: " << laptops.getModelPrizes()[i] << "$" << endl;
					}

					cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
					switch (item) {
					case 1:
						laptopsCase(1, &budget, laptops, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 2:
						laptopsCase(2, &budget, laptops, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 3:
						laptopsCase(3, &budget, laptops, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 4:
						laptopsCase(4, &budget, laptops, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 5:
						laptopsCase(5, &budget, laptops, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;
					case -1:
						isTrue = false;
						break;
					default:
						cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
					}
					isTrue = false;

				}
				else if (subIndex == 2) {

					cout << "\n";
					for (int i{ 0 }; i < phones.getModels().size(); i++) {
						cout << i + 1 << ". " << setw(26) << left << phones.getModels()[i] << "   \x1B[36mPrice\033[0m: " << phones.getModelPrizes()[i] << "$" << endl;
					}

					cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
					switch (item) {
					case 1:
						phonesCase(1, &budget, phones, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 2:
						phonesCase(2, &budget, phones, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 3:
						phonesCase(3, &budget, phones, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 4:
						phonesCase(4, &budget, phones, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 5:
						phonesCase(5, &budget, phones, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;
					case -1:
						isTrue = false;
						break;
					default:
						cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
					}
					isTrue = false;

				}
				else if (subIndex == 3) {

					cout << "\n";
					for (int i{ 0 }; i < televisions.getModels().size(); i++) {
						cout << i + 1 << ". " << setw(18) << left << televisions.getModels()[i] << "   \x1B[36mPrice\033[0m: " << televisions.getModelPrizes()[i] << "$" << endl;
					}

					cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
					switch (item) {
					case 1:
						televisionsCase(1, &budget, televisions, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 2:
						televisionsCase(2, &budget, televisions, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 3:
						televisionsCase(3, &budget, televisions, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 4:
						televisionsCase(4, &budget, televisions, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;

					case 5:
						televisionsCase(5, &budget, televisions, electronics, food, clothes, purchasedElectronics, name, initialBudget);
						cin >> index;
						break;
					case -1:
						isTrue = false;
						break;
					default:
						cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
					}
					isTrue = false;
				}
				else {isTrue = false;}
			}
		}
		else if (index == 2) {
		    Fruits fruits{ name, budget, "FOOD", "Fruits", {"Apples", "Bananas", "Oranges", "Peaches", "Apricots"}, {1.5, 2.4, 1.2, 3.2, 2.7} };
			Vegetables vegetables{ name, budget, "FOOD", "Vegetables", {"Tomatos", "Carrots", "Potatos", "Onions", "Cabbages"}, {0.6, 1.2, 0.5, 0.2 , 1.8} };
			Traditional traditional{ name, budget, "FOOD", "Traditional Meals", {"Manti", "Lagman", "Palov", "Kabab", "Chuchvara"}, {2.5, 0.3, 2.7, 1.3, 2.2} };

			vector<string> FoodSubCategories = { fruits.getSubcategoryName(), vegetables.getSubcategoryName(), traditional.getSubcategoryName() };

			cout << "\n";
			for (int i{ 0 }; i < FoodSubCategories.size(); i++) {
				cout << i + 1 << ". " << FoodSubCategories[i] << endl;
			}

			cout << "\nEnter the index of subcategory: ";
			int subIndex;
			cin >> subIndex;
			bool isTrue = true;
			while (isTrue) {
				if (subIndex == 1) {

					cout << "\n";
					for (int i{ 0 }; i < fruits.getTypes().size(); i++) {
						cout << i + 1 << ". " << setw(8) << left << fruits.getTypes()[i] << "   \x1B[36mPrice\033[0m: " << fruits.getTypePrizes()[i] << "$" << endl;
					}

					cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
					switch (item) {
					case 1:
						fruitsCase(1, &budget, fruits, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 2:
						fruitsCase(2, &budget, fruits, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 3:
						fruitsCase(3, &budget, fruits, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 4:
						fruitsCase(4, &budget, fruits, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 5:
						fruitsCase(5, &budget, fruits, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;
					case -1:
						isTrue = false;
						break;
					default:
						cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
					}
					isTrue = false;

				}
				else if (subIndex == 2) {

					cout << "\n";
					for (int i{ 0 }; i < vegetables.getTypes().size(); i++) {
						cout << i + 1 << ". " << setw(8) << left << vegetables.getTypes()[i] << "   \x1B[36mPrice\033[0m: " << vegetables.getTypePrizes()[i] << "$" << endl;
					}

					cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
					switch (item) {
					case 1:
						vegetablesCase(1, &budget, vegetables, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 2:
						vegetablesCase(2, &budget, vegetables, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 3:
						vegetablesCase(2, &budget, vegetables, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 4:
						vegetablesCase(4, &budget, vegetables, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 5:
						vegetablesCase(5, &budget, vegetables, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;
					case -1:
						isTrue = false;
						break;
					default:
						cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
					}
					isTrue = false;

				}
				else if (subIndex == 3) {

					cout << "\n";
					for (int i{ 0 }; i < traditional.getTypes().size(); i++) {
						cout << i + 1 << ". " << setw(10) << left << traditional.getTypes()[i] << "   \x1B[36mPrice\033[0m: " << traditional.getTypePrizes()[i] << "$" << endl;
					}

					cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
					switch (item) {
					case 1:
						traditionalCase(1, &budget, traditional, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 2:
						traditionalCase(2, &budget, traditional, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 3:
						traditionalCase(3, &budget, traditional, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 4:
						traditionalCase(4, &budget, traditional, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;

					case 5:
						traditionalCase(5, &budget, traditional, electronics, food, clothes, purchasedFoodQuantities, purchasedFood, name, initialBudget);
						cin >> index;
						break;
					case -1:
						isTrue = false;
						break;
					default:
						cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
					}
					isTrue = false;
				}
				else {isTrue = false;}
			}
		}
		else if (index == 3) {
		Boots boots{ name, budget, "CLOTHES", "Boots", {"Sneakers", "Flip-flops", "Rain Boots", "Classic Boots", "Heled Bootie"}, {10, 8, 189, 145, 250} };
		Tshirts tshirts{ name, budget, "CLOTHES", "Tshirts", {"Just Do It", "Nike", "Gucci", "Adidas", "Lacoste"}, {23, 7, 18, 5, 35} };
		Hats hats{ name, budget, "CLOTHES", "Hats", {"Panama", "Floppi", "BaseBall Cap", "Cowboy Hat", "Bucket"}, {45, 15, 23, 17, 28} };

		vector<string> ClothesSubCategories = { boots.getSubcategoryName(), tshirts.getSubcategoryName(), hats.getSubcategoryName() };

		cout << "\n";
		for (int i{ 0 }; i < ClothesSubCategories.size(); i++) {
			cout << i + 1 << ". " << ClothesSubCategories[i] << endl;
		}

		cout << "\nEnter the index of subcategory: ";
		int subIndex;
		cin >> subIndex;
		bool isTrue = true;
		while (isTrue) {
			if (subIndex == 1) {

				cout << "\n";
				for (int i{ 0 }; i < boots.getBrands().size(); i++) {
					cout << i + 1 << ". " << setw(14) << left << boots.getBrands()[i] << "   \x1B[36mPrice\033[0m: " << boots.getBrandPrizes()[i] << "$" << endl;
				}

				cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
				switch (item) {
				case 1:
					bootsCase(1, &budget, boots, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 2:
					bootsCase(2, &budget, boots, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 3:
					bootsCase(3, &budget, boots, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 4:
					bootsCase(4, &budget, boots, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 5:
					bootsCase(5, &budget, boots, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;
				case -1:
					isTrue = false;
					break;
				default:
					cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
				}
				isTrue = false;

			}
			else if (subIndex == 2) {

				cout << "\n";
				for (int i{ 0 }; i < tshirts.getBrands().size(); i++) {
					cout << i + 1 << ". " << setw(14) << left << tshirts.getBrands()[i] << "   \x1B[36mPrice\033[0m: " << tshirts.getBrandPrizes()[i] << "$" << endl;
				}

				cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
				switch (item) {
				case 1:
					tshirtsCase(1, &budget, tshirts, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 2:
					tshirtsCase(2, &budget, tshirts, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 3:
					tshirtsCase(3, &budget, tshirts, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 4:
					tshirtsCase(4, &budget, tshirts, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 5:
					tshirtsCase(5, &budget, tshirts, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;
				case -1:
					isTrue = false;
					break;
				default:
					cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
				}
				isTrue = false;

			}
			else if (subIndex == 3) {

				cout << "\n";
				for (int i{ 0 }; i < hats.getBrands().size(); i++) {
					cout << i + 1 << ". " << setw(14) << left << hats.getBrands()[i] << "   \x1B[36mPrice\033[0m: " << hats.getBrandPrizes()[i] << "$" << endl;
				}

				cout << "\nChoose any of them to buy or -1 to quit: "; int item; cin >> item;
				switch (item) {
				case 1:
					hatsCase(1, &budget, hats, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 2:
					hatsCase(2, &budget, hats, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 3:
					hatsCase(3, &budget, hats, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 4:
					hatsCase(4, &budget, hats, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;

				case 5:
					hatsCase(5, &budget, hats, electronics, food, clothes, purchasedClothes, name, initialBudget);
					cin >> index;
					break;
				case -1:
					isTrue = false;
					break;
				default:
					cout << "\nPlease make sure to enter \x1B[31mvalid item number\033[0m.\n";
				}
				isTrue = false;
			}
			else { isTrue = false; }
		}
		}
		else {
			cout << "\nTry again and make sure to enter proper index number.\n"
				<< "Enter the index of category or -1 to quit: ";
			cin >> index;
		}

	}
	

	system("cls");
	welcome(name);
	
	int numPurchasedItems = purchasedClothes.size() + purchasedElectronics.size() + purchasedFood.size();

	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << budget << "$" << endl;

	cout << "\n\x1B[36mYou bought:\033[0m \n\n";

	cout << electronics.getCategoryName() << "\n";

	if (purchasedElectronics.size() != 0) {
		for (int i{ 0 }; i < purchasedElectronics.size(); i++) {
			cout << i + 1 << ". " << purchasedElectronics[i] << endl;
		}
	}
	else
		cout << "You did not buy any electronics\n";

	cout << "\n" << food.getCategoryName() << "\n";

	if (purchasedFood.size() != 0) {
		for (int i{ 0 }; i < purchasedFood.size(); i++) {
			cout << i + 1 << ". " << setw(11) << left << purchasedFood[i] << "Quantity: " << purchasedFoodQuantities[i] << endl;
		}
	}
	else
		cout << "You did not buy any food\n";

	cout << "\n" << clothes.getCategoryName() << "\n";

	if (purchasedClothes.size() != 0) {
		for (int i{ 0 }; i < purchasedClothes.size(); i++) {
			cout << i + 1 << ". " << purchasedClothes[i] << endl;
		}
	}
	else
		cout << "You did not buy any Clothes\n";

	if (numPurchasedItems != 0) {
		cout << "\n\x1B[35mThe products you bought will be delivered within a short time.\033[0m\n"
			<< "\033[3;44;30mThanks for your purchase!!!\033[0m\n\n";
	}
	else
		cout << "\n\x1B[33mThanks for considering our products!!!\033[0m\n\n";

	system("pause>0");
	return 0;
}


// electronics

void laptopsCase(int caseIndex, double* budget, Laptops laptops, Electronics electronics, Food food, Clothes clothes, vector<string>& purchasedElectronics, string name, double initialBudget) {
	if ((*budget - laptops.getModelPrizes()[caseIndex-1]) >= 0) {
		*budget -= laptops.getModelPrizes()[caseIndex-1];
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << laptops.getModels()[caseIndex-1] << "\n\n";
		purchasedElectronics.push_back(laptops.getModels()[caseIndex-1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}

void phonesCase(int caseIndex, double* budget, Phones phones, Electronics electronics, Food food, Clothes clothes, vector<string>& purchasedElectronics, string name, double initialBudget) {
	if ((*budget - phones.getModelPrizes()[caseIndex-1]) >= 0) {
		*budget -= phones.getModelPrizes()[caseIndex-1];
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << phones.getModels()[caseIndex-1] << "\n\n";
		purchasedElectronics.push_back(phones.getModels()[caseIndex - 1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}

void televisionsCase(int caseIndex, double* budget, Televisions televisions, Electronics electronics, Food food, Clothes clothes, vector<string>& purchasedElectronics, string name, double initialBudget) {
	if ((*budget - televisions.getModelPrizes()[caseIndex-1]) >= 0) {
		*budget -= televisions.getModelPrizes()[caseIndex-1];
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << televisions.getModels()[caseIndex-1] << "\n\n";
		purchasedElectronics.push_back(televisions.getModels()[caseIndex-1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}


// food

void fruitsCase(int caseIndex, double* budget, Fruits fruits, Electronics electronics, Food food, Clothes clothes, vector<float>& purchasedFoodQuantities, vector<string>& purchasedFood, string name, double initialBudget) {
	cout << "How many kilograms you want: ";
	float fruitQuan;
	cin >> fruitQuan;
	if ((*budget - fruits.getTypePrizes()[caseIndex-1] * fruitQuan) >= 0) {
		*budget -= fruits.getTypePrizes()[caseIndex-1] * fruitQuan;
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << fruitQuan << " kg " << fruits.getTypes()[caseIndex-1] << "\n\n";
		purchasedFoodQuantities.push_back(fruitQuan);
		purchasedFood.push_back(fruits.getTypes()[caseIndex-1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}

void vegetablesCase(int caseIndex, double* budget, Vegetables vegetables, Electronics electronics, Food food, Clothes clothes, vector<float>& purchasedFoodQuantities, vector<string>& purchasedFood, string name, double initialBudget) {
	cout << "How many kilograms you want: ";
	float vegetableQuan;
	cin >> vegetableQuan;
	if ((*budget - vegetables.getTypePrizes()[caseIndex-1] * vegetableQuan) >= 0) {
		*budget -= vegetables.getTypePrizes()[caseIndex-1] * vegetableQuan;
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << vegetableQuan << " kg " << vegetables.getTypes()[caseIndex-1] << "\n\n";
		purchasedFoodQuantities.push_back(vegetableQuan);
		purchasedFood.push_back(vegetables.getTypes()[caseIndex-1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}

void traditionalCase(int caseIndex, double* budget, Traditional traditional, Electronics electronics, Food food, Clothes clothes, vector<float>& purchasedFoodQuantities, vector<string>& purchasedFood, string name, double initialBudget) {
	cout << "How many plates you want: ";
	int traQuan;
	cin >> traQuan;
	if ((*budget - traditional.getTypePrizes()[caseIndex-1] * traQuan) >= 0) {
		*budget -= traditional.getTypePrizes()[caseIndex-1] * traQuan;
		if (traQuan == 1)
			cout << "\n\x1B[36mSuccess!\033[0m You bought " << traQuan << " a plate of " << traditional.getTypes()[caseIndex-1] << "\n\n";
		else
			cout << "\n\x1B[36mSuccess!\033[0m You bought " << traQuan << " plates of " << traditional.getTypes()[caseIndex-1] << "\n\n";
		purchasedFoodQuantities.push_back(traQuan);
		purchasedFood.push_back(traditional.getTypes()[caseIndex-1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}


// clothes
void bootsCase(int caseIndex, double* budget, Boots boots, Electronics electronics, Food food, Clothes clothes, vector<string>& purchasedClothes, string name, double initialBudget) {
	if ((*budget - boots.getBrandPrizes()[caseIndex - 1]) >= 0) {
		*budget -= boots.getBrandPrizes()[caseIndex - 1];
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << boots.getBrands()[caseIndex - 1] << "\n\n";
		purchasedClothes.push_back(boots.getBrands()[caseIndex - 1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}

void tshirtsCase(int caseIndex, double* budget, Tshirts tshirts, Electronics electronics, Food food, Clothes clothes, vector<string>& purchasedClothes, string name, double initialBudget) {
	if ((*budget - tshirts.getBrandPrizes()[caseIndex - 1]) >= 0) {
		*budget -= tshirts.getBrandPrizes()[caseIndex - 1];
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << tshirts.getBrands()[caseIndex - 1] << "\n\n";
		purchasedClothes.push_back(tshirts.getBrands()[caseIndex - 1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}

void hatsCase(int caseIndex, double* budget, Hats hats, Electronics electronics, Food food, Clothes clothes, vector<string>& purchasedClothes, string name, double initialBudget) {
	if ((*budget - hats.getBrandPrizes()[caseIndex - 1]) >= 0) {
		*budget -= hats.getBrandPrizes()[caseIndex - 1];
		cout << "\n\x1B[36mSuccess!\033[0m You bought " << hats.getBrands()[caseIndex - 1] << "\n\n";
		purchasedClothes.push_back(hats.getBrands()[caseIndex - 1]);
	}
	else
		cout << "\n\x1B[31mYou do not have enough money\033[0m\n\n";

	Sleep(2000);
	system("cls");

	welcome(name);
	cout << "Your \x1B[32minitial\033[0m budget is " << initialBudget << "$" << endl
		<< "Your \x1B[31mremaining\033[0m budget: " << *budget << "$" << endl
		<< "\n\x1B[31m<<\033[0mChoose any category you like to buy our products\x1B[31m>>\033[0m\n\n"
		<< "\x1B[36m1\033[0m." << electronics.getCategoryName() << setw(24) << right << "\x1B[36m2\033[0m." << food.getCategoryName() << setw(27) << right << "\x1B[36m3\033[0m." << clothes.getCategoryName() << "\n\n"
		<< "Enter the index of category or -1 to quit: ";
}
