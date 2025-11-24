#ifndef MAINCOURSE_H
#define MAINCOURSE_H

#include "MenuItem.h"
#include <vector>

class MainCourse : public MenuItem {
private:
    std::vector<std::string> toppings;
    std::vector<double> toppingPrices;
    std::string preparationOption; // Grilled, Fried, Baked, etc.
    std::string size; // Small, Medium, Large

public:
    // Constructor
    MainCourse(const std::string& name, const std::string& description,
               double basePrice, bool available = true,
               const std::string& imagePath = "",
               const std::string& preparationOption = "Standard",
               const std::string& size = "Medium");
    
    // Override pure virtual function
    double getPrice() const override;
    
    // Override display function
    void displayDetails() const override;
    
    // Topping management
    void addTopping(const std::string& topping, double price);
    void removeTopping(const std::string& topping);
    void clearToppings();
    
    // Getters
    std::vector<std::string> getToppings() const;
    std::string getPreparationOption() const;
    std::string getSize() const;
    
    // Setters
    void setPreparationOption(const std::string& option);
    void setSize(const std::string& size);
};

#endif
