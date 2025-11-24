#ifndef MANAGER_H
#define MANAGER_H

#include "MenuItem.h"
#include "OrderQueue.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

class Manager {
private:
    std::string name;
    std::string employeeId;
    std::vector<std::shared_ptr<MenuItem>> menu;
    OrderQueue* orderQueue; // Aggregation - Manager uses but doesn't own OrderQueue

public:
    // Constructor
    Manager(const std::string& name, const std::string& employeeId, 
            OrderQueue* orderQueue = nullptr);
    
    // Menu management
    void addMenuItem(std::shared_ptr<MenuItem> item);
    void removeMenuItem(const std::string& itemName);
    void updateMenuItemPrice(const std::string& itemName, double newPrice);
    void updateMenuItemAvailability(const std::string& itemName, bool available);
    void displayMenu() const;
    void displayMenuByCategory(const std::string& category) const;
    
    // Search menu
    std::shared_ptr<MenuItem> findMenuItem(const std::string& itemName) const;
    std::vector<std::shared_ptr<MenuItem>> getMenuItemsByCategory(const std::string& category) const;
    
    // Sales and analytics
    void viewSalesReport() const;
    void viewOrderHistory() const;
    double calculateTotalRevenue() const;
    int getTotalOrdersProcessed() const;
    double getAverageOrderValue() const;
    std::map<std::string, double> getCategorySalesBreakdown() const;
    
    // Getters
    std::string getName() const;
    std::string getEmployeeId() const;
    std::vector<std::shared_ptr<MenuItem>> getMenu() const;
    OrderQueue* getOrderQueue() const;
    
    // Setters
    void setName(const std::string& name);
    void setEmployeeId(const std::string& employeeId);
    void setOrderQueue(OrderQueue* queue);
};

#endif
