#include "Product.h"

Product::Product(){};
Product::Product(std::string newName, int newPrice, int newQuantity)
    : name(newName), price(newPrice), quantity(newQuantity) {};

std::string Product::getName() const { return name; }
int Product::getPrice() const { return price; } 
int Product::getQuantity() const { return quantity};

void Product::setName(std::string newName) { name = newName; }
void Product::setPrice(int newPrice) { price = newPrice; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
