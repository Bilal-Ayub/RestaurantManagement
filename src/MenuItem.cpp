#include "MenuItem.h"
#include <iostream>

using namespace std;

MenuItem::MenuItem(const string& name, const string& description,
                   double basePrice, const string& category,
                   bool available, const string& imagePath)
    : name(name), description(description), basePrice(basePrice),
      category(category), available(available), imagePath(imagePath) {}

MenuItem::~MenuItem() {}

void MenuItem::displayDetails() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Base Price: $" << basePrice << std::endl;
    std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
}

// Getters
string MenuItem::getName() const { return name; }
string MenuItem::getDescription() const { return description; }
double MenuItem::getBasePrice() const { return basePrice; }
string MenuItem::getCategory() const { return category; }
bool MenuItem::isAvailable() const { return available; }
string MenuItem::getImagePath() const { return imagePath; }

// Setters
void MenuItem::setName(const string& name) { this->name = name; }
void MenuItem::setDescription(const string& description) { this->description = description; }
void MenuItem::setBasePrice(double price) { this->basePrice = price; }
void MenuItem::setCategory(const string& category) { this->category = category; }
void MenuItem::setAvailable(bool available) { this->available = available; }
void MenuItem::setImagePath(const string& imagePath) { this->imagePath = imagePath; }
