#include "Order.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Order::nextOrderId = 1000;

Order::Order(const string& customerName)
    : orderId(nextOrderId++), status("Received"), 
      timestamp(time(nullptr)), customerName(customerName) {}

void Order::addItem(std::shared_ptr<MenuItem> item, const std::string& instructions) {
    if (item != nullptr) {
        items.push_back(item);
        specialInstructions.push_back(instructions);
    }
}

void Order::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        items.erase(items.begin() + index);
        specialInstructions.erase(specialInstructions.begin() + index);
    }
}

void Order::clearOrder() {
    items.clear();
    specialInstructions.clear();
}

double Order::getSubtotal() const {
    double subtotal = 0.0;
    for (const auto& item : items) {
        subtotal += item->getPrice();
    }
    return subtotal;
}

double Order::getTax(double taxRate) const {
    return getSubtotal() * taxRate;
}

double Order::getTotal(double taxRate) const {
    return getSubtotal() + getTax(taxRate);
}

void Order::setStatus(const string& status) {
    this->status = status;
}

string Order::getStatus() const {
    return status;
}

void Order::displayOrder() const {
    std::cout << "========================================" << std::endl;
    std::cout << "Order #" << orderId << std::endl;
    std::cout << "Customer: " << customerName << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "========================================" << std::endl;
    
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << "\nItem " << (i + 1) << ":" << std::endl;
        items[i]->displayDetails();
        if (!specialInstructions[i].empty()) {
            std::cout << "Special Instructions: " << specialInstructions[i] << std::endl;
        }
    }
    
    cout << "\n========================================" << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << getSubtotal() << endl;
    cout << "Tax (13%): $" << getTax() << endl;
    cout << "Total: $" << getTotal() << endl;
    cout << "========================================" << endl;
}

// Getters
int Order::getOrderId() const { return orderId; }
time_t Order::getTimestamp() const { return timestamp; }
string Order::getCustomerName() const { return customerName; }
vector<shared_ptr<MenuItem>> Order::getItems() const { return items; }
vector<string> Order::getSpecialInstructions() const { return specialInstructions; }
int Order::getItemCount() const { return items.size(); }

// Setters
void Order::setCustomerName(const string& name) { this->customerName = name; }
