#include "Dessert.h"
#include <iostream>

using namespace std;

Dessert::Dessert(const string& name, const string& description,
                 double basePrice, bool available,
                 const string& imagePath,
                 bool containsNuts,
                 const string& sugarLevel,
                 bool glutenFree)
    : MenuItem(name, description, basePrice, "Dessert", available, imagePath),
      containsNuts(containsNuts), sugarLevel(sugarLevel), glutenFree(glutenFree) {}

double Dessert::getPrice() const {
    double price = basePrice;
    
    // Premium for gluten-free options
    if (glutenFree) {
        price *= 1.15;
    }
    
    return price;
}

void Dessert::displayDetails() const {
    MenuItem::displayDetails();
    std::cout << "Sugar Level: " << sugarLevel << std::endl;
    std::cout << "Contains Nuts: " << (containsNuts ? "Yes" : "No") << std::endl;
    std::cout << "Gluten Free: " << (glutenFree ? "Yes" : "No") << std::endl;
    std::cout << "Final Price: $" << getPrice() << std::endl;
}

// Getters
bool Dessert::hasNuts() const { return containsNuts; }
string Dessert::getSugarLevel() const { return sugarLevel; }
bool Dessert::isGlutenFree() const { return glutenFree; }

// Setters
void Dessert::setContainsNuts(bool containsNuts) { this->containsNuts = containsNuts; }
void Dessert::setSugarLevel(const string& level) { this->sugarLevel = level; }
void Dessert::setGlutenFree(bool glutenFree) { this->glutenFree = glutenFree; }
