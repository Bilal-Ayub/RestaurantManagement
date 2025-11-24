#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "MenuItem.h"

class Beverage : public MenuItem {
private:
    std::string size; // Small, Medium, Large
    std::string temperature; // Hot, Cold, Room Temperature
    bool containsCaffeine;

public:
    // Constructor
    Beverage(const std::string& name, const std::string& description,
             double basePrice, bool available = true,
             const std::string& imagePath = "",
             const std::string& size = "Medium",
             const std::string& temperature = "Cold",
             bool containsCaffeine = false);
    
    // Override pure virtual function
    double getPrice() const override;
    
    // Override display function
    void displayDetails() const override;
    
    // Getters
    std::string getSize() const;
    std::string getTemperature() const;
    bool hasCaffeine() const;
    
    // Setters
    void setSize(const std::string& size);
    void setTemperature(const std::string& temperature);
    void setContainsCaffeine(bool containsCaffeine);
};

#endif
