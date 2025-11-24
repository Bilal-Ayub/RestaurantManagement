#include "MainCourse.h"
#include <iostream>
#include <algorithm>

using namespace std;

MainCourse::MainCourse(const string& name, const string& description,
                       double basePrice, bool available,
                       const string& imagePath,
                       const string& preparationOption,
                       const string& size)
    : MenuItem(name, description, basePrice, "Main Course", available, imagePath),
      preparationOption(preparationOption), size(size) {}

double MainCourse::getPrice() const {
    double price = basePrice;
    
    // Adjust price based on size
    if (size == "Small") {
        price *= 0.85;
    } else if (size == "Large") {
        price *= 1.4;
    }
    
    // Add topping prices
    for (double toppingPrice : toppingPrices) {
        price += toppingPrice;
    }
    
    return price;
}

void MainCourse::displayDetails() const {
    MenuItem::displayDetails();
    std::cout << "Size: " << size << std::endl;
    std::cout << "Preparation: " << preparationOption << std::endl;
    
    if (!toppings.empty()) {
        std::cout << "Toppings: ";
        for (size_t i = 0; i < toppings.size(); ++i) {
            std::cout << toppings[i];
            if (i < toppings.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Final Price: $" << getPrice() << std::endl;
}

void MainCourse::addTopping(const string& topping, double price) {
    toppings.push_back(topping);
    toppingPrices.push_back(price);
}

void MainCourse::removeTopping(const string& topping) {
    auto it = find(toppings.begin(), toppings.end(), topping);
    if (it != toppings.end()) {
        size_t index = distance(toppings.begin(), it);
        toppings.erase(it);
        toppingPrices.erase(toppingPrices.begin() + index);
    }
}

void MainCourse::clearToppings() {
    toppings.clear();
    toppingPrices.clear();
}

// Getters
vector<string> MainCourse::getToppings() const { return toppings; }
string MainCourse::getPreparationOption() const { return preparationOption; }
string MainCourse::getSize() const { return size; }

// Setters
void MainCourse::setPreparationOption(const string& option) { this->preparationOption = option; }
void MainCourse::setSize(const string& size) { this->size = size; }
