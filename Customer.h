#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include "MenuItem.h"
#include <string>
#include <memory>
#include <vector>

class Customer {
private:
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::shared_ptr<Order> currentOrder;
    std::vector<std::shared_ptr<Order>> orderHistory;

public:
    // Constructor
    Customer(const std::string& name, const std::string& phoneNumber = "", 
             const std::string& email = "");
    
    // Order management
    void startNewOrder();
    void addItemToCart(std::shared_ptr<MenuItem> item, const std::string& instructions = "");
    void removeItemFromCart(int index);
    void viewCart() const;
    void clearCart();
    
    // Place order
    std::shared_ptr<Order> placeOrder();
    
    // View order history
    void viewOrderHistory() const;
    
    // Getters
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::shared_ptr<Order> getCurrentOrder() const;
    std::vector<std::shared_ptr<Order>> getOrderHistory() const;
    
    // Setters
    void setName(const std::string& name);
    void setPhoneNumber(const std::string& phoneNumber);
    void setEmail(const std::string& email);
};

#endif
