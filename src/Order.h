#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <vector>
#include <string>
#include <memory>
#include <ctime>

class Order {
private:
    static int nextOrderId;
    int orderId;
    std::vector<std::shared_ptr<MenuItem>> items;
    std::vector<std::string> specialInstructions;
    std::string status; // Received, Preparing, Ready
    std::time_t timestamp;
    std::string customerName;

public:
    // Constructor
    Order(const std::string& customerName = "Guest");
    
    // Order management
    void addItem(std::shared_ptr<MenuItem> item, const std::string& instructions = "");
    void removeItem(int index);
    void clearOrder();
    
    // Calculate order total
    double getSubtotal() const;
    double getTax(double taxRate = 0.13) const;
    double getTotal(double taxRate = 0.13) const;
    
    // Order status management
    void setStatus(const std::string& status);
    std::string getStatus() const;
    
    // Display order
    void displayOrder() const;
    
    // Getters
    int getOrderId() const;
    std::time_t getTimestamp() const;
    std::string getCustomerName() const;
    std::vector<std::shared_ptr<MenuItem>> getItems() const;
    std::vector<std::string> getSpecialInstructions() const;
    int getItemCount() const;
    
    // Setters
    void setCustomerName(const std::string& name);
};

#endif
