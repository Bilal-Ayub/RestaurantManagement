#ifndef APPETIZER_H
#define APPETIZER_H

#include "MenuItem.h"

class Appetizer : public MenuItem {
private:
    std::string portionSize; // Small, Medium, Large
    std::string spiceLevel;  // Mild, Medium, Hot

public:
    // Constructor
    Appetizer(const std::string& name, const std::string& description,
              double basePrice, bool available = true,
              const std::string& imagePath = "",
              const std::string& portionSize = "Medium",
              const std::string& spiceLevel = "Mild");
    
    // Override pure virtual function
    double getPrice() const override;
    
    // Override display function
    void displayDetails() const override;
    
    // Getters
    std::string getPortionSize() const;
    std::string getSpiceLevel() const;
    
    // Setters
    void setPortionSize(const std::string& size);
    void setSpiceLevel(const std::string& level);
};

#endif
