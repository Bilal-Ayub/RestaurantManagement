#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(const string& name, const string& phoneNumber, 
                   const string& email)
    : name(name), phoneNumber(phoneNumber), email(email), currentOrder(nullptr) {}

void Customer::startNewOrder() {
    currentOrder = make_shared<Order>(name);
}

void Customer::addItemToCart(shared_ptr<MenuItem> item, const string& instructions) {
    if (currentOrder == nullptr) {
        startNewOrder();
    }
    currentOrder->addItem(item, instructions);
}

void Customer::removeItemFromCart(int index) {
    if (currentOrder != nullptr) {
        currentOrder->removeItem(index);
    }
}

void Customer::viewCart() const {
    if (currentOrder == nullptr || currentOrder->getItemCount() == 0) {
        std::cout << "Your cart is empty." << std::endl;
    } else {
        std::cout << "\n=== YOUR CART ===" << std::endl;
        currentOrder->displayOrder();
    }
}

void Customer::clearCart() {
    if (currentOrder != nullptr) {
        currentOrder->clearOrder();
    }
}

shared_ptr<Order> Customer::placeOrder() {
    if (currentOrder == nullptr || currentOrder->getItemCount() == 0) {
        cout << "Cannot place an empty order." << endl;
        return nullptr;
    }
    
    shared_ptr<Order> placedOrder = currentOrder;
    orderHistory.push_back(placedOrder);
    
    std::cout << "\nOrder #" << placedOrder->getOrderId() 
              << " placed successfully!" << std::endl;
    
    currentOrder = nullptr; // Reset current order
    return placedOrder;
}

void Customer::viewOrderHistory() const {
    if (orderHistory.empty()) {
        std::cout << "No order history available." << std::endl;
    } else {
        std::cout << "\n=== ORDER HISTORY ===" << std::endl;
        for (const auto& order : orderHistory) {
            order->displayOrder();
            std::cout << std::endl;
        }
    }
}

// Getters
string Customer::getName() const { return name; }
string Customer::getPhoneNumber() const { return phoneNumber; }
string Customer::getEmail() const { return email; }
shared_ptr<Order> Customer::getCurrentOrder() const { return currentOrder; }
vector<shared_ptr<Order>> Customer::getOrderHistory() const { return orderHistory; }

// Setters
void Customer::setName(const string& name) { this->name = name; }
void Customer::setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }
void Customer::setEmail(const string& email) { this->email = email; }
