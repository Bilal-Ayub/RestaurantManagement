#include "Beverage.h"
#include <iostream>

using namespace std;

Beverage::Beverage(const string& name, const string& description,
                   double basePrice, bool available,
                   const string& imagePath,
                   const string& size,
                   const string& temperature,
                   bool containsCaffeine)
    : MenuItem(name, description, basePrice, "Beverage", available, imagePath),
      size(size), temperature(temperature), containsCaffeine(containsCaffeine) {}

double Beverage::getPrice() const {
    double price = basePrice;
    
    // Adjust price based on size
    if (size == "Small") {
        price *= 0.75;
    } else if (size == "Large") {
        price *= 1.5;
    }
    
    return price;
}

void Beverage::displayDetails() const {
    MenuItem::displayDetails();
    std::cout << "Size: " << size << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
    std::cout << "Contains Caffeine: " << (containsCaffeine ? "Yes" : "No") << std::endl;
    std::cout << "Final Price: $" << getPrice() << std::endl;
}

// Getters
string Beverage::getSize() const { return size; }
string Beverage::getTemperature() const { return temperature; }
bool Beverage::hasCaffeine() const { return containsCaffeine; }

// Setters
void Beverage::setSize(const string& size) { this->size = size; }
void Beverage::setTemperature(const string& temperature) { this->temperature = temperature; }
void Beverage::setContainsCaffeine(bool containsCaffeine) { this->containsCaffeine = containsCaffeine; }
