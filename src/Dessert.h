#ifndef DESSERT_H
#define DESSERT_H

#include "MenuItem.h"

class Dessert : public MenuItem {
private:
    bool containsNuts;
    std::string sugarLevel; // Low, Medium, High
    bool glutenFree;

public:
    // Constructor
    Dessert(const std::string& name, const std::string& description,
            double basePrice, bool available = true,
            const std::string& imagePath = "",
            bool containsNuts = false,
            const std::string& sugarLevel = "Medium",
            bool glutenFree = false);
    
    // Override pure virtual function
    double getPrice() const override;
    
    // Override display function
    void displayDetails() const override;
    
    // Getters
    bool hasNuts() const;
    std::string getSugarLevel() const;
    bool isGlutenFree() const;
    
    // Setters
    void setContainsNuts(bool containsNuts);
    void setSugarLevel(const std::string& level);
    void setGlutenFree(bool glutenFree);
};

#endif
