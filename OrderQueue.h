#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include "Order.h"
#include <vector>
#include <memory>
#include <queue>

class OrderQueue {
private:
    std::vector<std::shared_ptr<Order>> pendingOrders;
    std::vector<std::shared_ptr<Order>> preparingOrders;
    std::vector<std::shared_ptr<Order>> completedOrders;

public:
    // Constructor
    OrderQueue();
    
    // Order management
    void addOrder(std::shared_ptr<Order> order);
    void moveToPreparation(int orderId);
    void markAsComplete(int orderId);
    
    // Find orders
    std::shared_ptr<Order> findOrder(int orderId);
    std::vector<std::shared_ptr<Order>> getOrdersByStatus(const std::string& status);
    
    // Display methods
    void displayPendingOrders() const;
    void displayPreparingOrders() const;
    void displayCompletedOrders() const;
    void displayAllOrders() const;
    
    // Getters
    std::vector<std::shared_ptr<Order>> getPendingOrders() const;
    std::vector<std::shared_ptr<Order>> getPreparingOrders() const;
    std::vector<std::shared_ptr<Order>> getCompletedOrders() const;
    
    int getPendingCount() const;
    int getPreparingCount() const;
    int getCompletedCount() const;
    int getTotalCount() const;
};

#endif
