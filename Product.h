#pragma once
#include <string>

class Product
{
public:
	// Constructor
	Product();
	Product(std::string newName, int newPrice, int newQuantity);

	// Accessor and mutator functions
	// "const" modifier prevents the value of the calling object been changed by the program
	std::string getName() const;
	int getPrice() const;
	int getQuantity() const;

	void setName(std::string newName);
	void setPrice(int newPrice);
	void setQuantity(int newQuantity);

private:
	std::string name;
	int price;
	int quantity;
};

