#ifndef KITCHEN_H
#define KITCHEN_H

#include "OrderQueue.h"
#include "Order.h"
#include <memory>
#include <string>

class Kitchen {
private:
    std::string kitchenName;
    OrderQueue* orderQueue; // Aggregation - Kitchen uses but doesn't own OrderQueue

public:
    // Constructor
    Kitchen(const std::string& kitchenName, OrderQueue* orderQueue);
    
    // Order processing
    void viewPendingOrders() const;
    void startPreparingOrder(int orderId);
    void completeOrder(int orderId);
    
    // Order details
    void viewOrderDetails(int orderId) const;
    
    // Display statistics
    void displayKitchenStatus() const;
    
    // Getters
    std::string getKitchenName() const;
    OrderQueue* getOrderQueue() const;
    
    // Setters
    void setKitchenName(const std::string& name);
    void setOrderQueue(OrderQueue* queue);
};

#endif
