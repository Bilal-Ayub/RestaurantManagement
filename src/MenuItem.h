#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

class MenuItem {
protected:
    std::string name;
    std::string description;
    double basePrice;
    std::string category;
    bool available;
    std::string imagePath;

public:
    // Constructor
    MenuItem(const std::string& name, const std::string& description, 
             double basePrice, const std::string& category, 
             bool available = true, const std::string& imagePath = "");
    
    // Virtual destructor for proper cleanup in derived classes
    virtual ~MenuItem();
    
    // Pure virtual function - makes this an abstract class
    virtual double getPrice() const = 0;
    
    // Virtual function for displaying item details
    virtual void displayDetails() const;
    
    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getBasePrice() const;
    std::string getCategory() const;
    bool isAvailable() const;
    std::string getImagePath() const;
    
    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setBasePrice(double price);
    void setCategory(const std::string& category);
    void setAvailable(bool available);
    void setImagePath(const std::string& imagePath);
};

#endif
