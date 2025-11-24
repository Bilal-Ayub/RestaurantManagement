#include "Manager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Manager::Manager(const string& name, const string& employeeId,
                 OrderQueue* orderQueue)
    : name(name), employeeId(employeeId), orderQueue(orderQueue) {}

void Manager::addMenuItem(shared_ptr<MenuItem> item) {
    if (item != nullptr) {
        menu.push_back(item);
        cout << "Added '" << item->getName() << "' to the menu." << endl;
    }
}

void Manager::removeMenuItem(const string& itemName) {
    auto it = find_if(menu.begin(), menu.end(),
                          [&itemName](const shared_ptr<MenuItem>& item) {
                              return item->getName() == itemName;
                          });
    
    if (it != menu.end()) {
        std::cout << "Removed '" << itemName << "' from the menu." << std::endl;
        menu.erase(it);
    } else {
        std::cout << "Item '" << itemName << "' not found in menu." << std::endl;
    }
}

void Manager::updateMenuItemPrice(const string& itemName, double newPrice) {
    auto item = findMenuItem(itemName);
    if (item != nullptr) {
        item->setBasePrice(newPrice);
        cout << "Updated price of '" << itemName << "' to $" << newPrice << endl;
    } else {
        cout << "Item '" << itemName << "' not found." << endl;
    }
}

void Manager::updateMenuItemAvailability(const string& itemName, bool available) {
    auto item = findMenuItem(itemName);
    if (item != nullptr) {
        item->setAvailable(available);
        std::cout << "Updated availability of '" << itemName << "' to " 
                  << (available ? "Available" : "Unavailable") << std::endl;
    } else {
        std::cout << "Item '" << itemName << "' not found." << std::endl;
    }
}

void Manager::displayMenu() const {
    if (menu.empty()) {
        std::cout << "Menu is empty." << std::endl;
    } else {
        std::cout << "\n=== FULL MENU ===" << std::endl;
        for (const auto& item : menu) {
            item->displayDetails();
            std::cout << "-------------------" << std::endl;
        }
    }
}

void Manager::displayMenuByCategory(const std::string& category) const {
    std::cout << "\n=== " << category << " ===" << std::endl;
    bool found = false;
    
    for (const auto& item : menu) {
        if (item->getCategory() == category) {
            item->displayDetails();
            std::cout << "-------------------" << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No items found in this category." << std::endl;
    }
}

shared_ptr<MenuItem> Manager::findMenuItem(const string& itemName) const {
    auto it = find_if(menu.begin(), menu.end(),
                          [&itemName](const shared_ptr<MenuItem>& item) {
                              return item->getName() == itemName;
                          });
    
    return (it != menu.end()) ? *it : nullptr;
}

vector<shared_ptr<MenuItem>> Manager::getMenuItemsByCategory(const string& category) const {
    vector<shared_ptr<MenuItem>> result;
    
    for (const auto& item : menu) {
        if (item->getCategory() == category) {
            result.push_back(item);
        }
    }
    
    return result;
}

void Manager::viewSalesReport() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         SALES REPORT" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Revenue: $" << calculateTotalRevenue() << std::endl;
    std::cout << "Total Orders Processed: " << getTotalOrdersProcessed() << std::endl;
    std::cout << "Average Order Value: $" << getAverageOrderValue() << std::endl;
    
    std::cout << "\n--- Category Sales Breakdown ---" << std::endl;
    auto categorySales = getCategorySalesBreakdown();
    for (const auto& [category, sales] : categorySales) {
        std::cout << category << ": $" << sales << std::endl;
    }
    std::cout << "========================================" << std::endl;
}

void Manager::viewOrderHistory() const {
    if (orderQueue != nullptr) {
        std::cout << "\n=== ORDER HISTORY ===" << std::endl;
        orderQueue->displayAllOrders();
    } else {
        std::cout << "No order queue available." << std::endl;
    }
}

double Manager::calculateTotalRevenue() const {
    if (orderQueue == nullptr) return 0.0;
    
    double revenue = 0.0;
    auto completedOrders = orderQueue->getCompletedOrders();
    
    for (const auto& order : completedOrders) {
        revenue += order->getTotal();
    }
    
    return revenue;
}

int Manager::getTotalOrdersProcessed() const {
    return (orderQueue != nullptr) ? orderQueue->getCompletedCount() : 0;
}

double Manager::getAverageOrderValue() const {
    int totalOrders = getTotalOrdersProcessed();
    if (totalOrders == 0) return 0.0;
    
    return calculateTotalRevenue() / totalOrders;
}

map<string, double> Manager::getCategorySalesBreakdown() const {
    map<string, double> categorySales;
    
    if (orderQueue == nullptr) return categorySales;
    
    auto completedOrders = orderQueue->getCompletedOrders();
    
    for (const auto& order : completedOrders) {
        for (const auto& item : order->getItems()) {
            string category = item->getCategory();
            categorySales[category] += item->getPrice();
        }
    }
    
    return categorySales;
}

// Getters
string Manager::getName() const { return name; }
string Manager::getEmployeeId() const { return employeeId; }
vector<shared_ptr<MenuItem>> Manager::getMenu() const { return menu; }
OrderQueue* Manager::getOrderQueue() const { return orderQueue; }

// Setters
void Manager::setName(const string& name) { this->name = name; }
void Manager::setEmployeeId(const string& employeeId) { this->employeeId = employeeId; }
void Manager::setOrderQueue(OrderQueue* queue) { this->orderQueue = queue; }
