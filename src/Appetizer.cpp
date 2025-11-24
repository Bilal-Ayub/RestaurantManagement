#include "Appetizer.h"
#include <iostream>

using namespace std;

Appetizer::Appetizer(const string& name, const string& description,
                     double basePrice, bool available,
                     const string& imagePath,
                     const string& portionSize,
                     const string& spiceLevel)
    : MenuItem(name, description, basePrice, "Appetizer", available, imagePath),
      portionSize(portionSize), spiceLevel(spiceLevel) {}

double Appetizer::getPrice() const {
    double price = basePrice;
    
    // Adjust price based on portion size
    if (portionSize == "Small") {
        price *= 0.8;
    } else if (portionSize == "Large") {
        price *= 1.3;
    }
    
    return price;
}

void Appetizer::displayDetails() const {
    MenuItem::displayDetails();
    std::cout << "Portion Size: " << portionSize << std::endl;
    std::cout << "Spice Level: " << spiceLevel << std::endl;
    std::cout << "Final Price: $" << getPrice() << std::endl;
}

// Getters
string Appetizer::getPortionSize() const { return portionSize; }
string Appetizer::getSpiceLevel() const { return spiceLevel; }

// Setters
void Appetizer::setPortionSize(const string& size) { this->portionSize = size; }
void Appetizer::setSpiceLevel(const string& level) { this->spiceLevel = level; }
