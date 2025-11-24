#include "OrderQueue.h"
#include <iostream>
#include <algorithm>

using namespace std;

OrderQueue::OrderQueue() {}

void OrderQueue::addOrder(std::shared_ptr<Order> order) {
    if (order != nullptr) {
        order->setStatus("Received");
        pendingOrders.push_back(order);
    }
}

void OrderQueue::moveToPreparation(int orderId) {
    auto it = find_if(pendingOrders.begin(), pendingOrders.end(),
                          [orderId](const shared_ptr<Order>& order) {
                              return order->getOrderId() == orderId;
                          });
    
    if (it != pendingOrders.end()) {
        (*it)->setStatus("Preparing");
        preparingOrders.push_back(*it);
        pendingOrders.erase(it);
    }
}

void OrderQueue::markAsComplete(int orderId) {
    auto it = find_if(preparingOrders.begin(), preparingOrders.end(),
                          [orderId](const shared_ptr<Order>& order) {
                              return order->getOrderId() == orderId;
                          });
    
    if (it != preparingOrders.end()) {
        (*it)->setStatus("Ready");
        completedOrders.push_back(*it);
        preparingOrders.erase(it);
    }
}

shared_ptr<Order> OrderQueue::findOrder(int orderId) {
    // Search in pending orders
    auto it = find_if(pendingOrders.begin(), pendingOrders.end(),
                          [orderId](const shared_ptr<Order>& order) {
                              return order->getOrderId() == orderId;
                          });
    if (it != pendingOrders.end()) return *it;
    
    // Search in preparing orders
    it = find_if(preparingOrders.begin(), preparingOrders.end(),
                     [orderId](const shared_ptr<Order>& order) {
                         return order->getOrderId() == orderId;
                     });
    if (it != preparingOrders.end()) return *it;
    
    // Search in completed orders
    it = find_if(completedOrders.begin(), completedOrders.end(),
                     [orderId](const shared_ptr<Order>& order) {
                         return order->getOrderId() == orderId;
                     });
    if (it != completedOrders.end()) return *it;
    
    return nullptr;
}

vector<shared_ptr<Order>> OrderQueue::getOrdersByStatus(const string& status) {
    if (status == "Received") return pendingOrders;
    else if (status == "Preparing") return preparingOrders;
    else if (status == "Ready") return completedOrders;
    return vector<shared_ptr<Order>>();
}

void OrderQueue::displayPendingOrders() const {
    std::cout << "\n=== PENDING ORDERS ===" << std::endl;
    if (pendingOrders.empty()) {
        std::cout << "No pending orders." << std::endl;
    } else {
        for (const auto& order : pendingOrders) {
            order->displayOrder();
            std::cout << std::endl;
        }
    }
}

void OrderQueue::displayPreparingOrders() const {
    std::cout << "\n=== PREPARING ORDERS ===" << std::endl;
    if (preparingOrders.empty()) {
        std::cout << "No orders being prepared." << std::endl;
    } else {
        for (const auto& order : preparingOrders) {
            order->displayOrder();
            std::cout << std::endl;
        }
    }
}

void OrderQueue::displayCompletedOrders() const {
    std::cout << "\n=== COMPLETED ORDERS ===" << std::endl;
    if (completedOrders.empty()) {
        std::cout << "No completed orders." << std::endl;
    } else {
        for (const auto& order : completedOrders) {
            order->displayOrder();
            std::cout << std::endl;
        }
    }
}

void OrderQueue::displayAllOrders() const {
    displayPendingOrders();
    displayPreparingOrders();
    displayCompletedOrders();
}

// Getters
vector<shared_ptr<Order>> OrderQueue::getPendingOrders() const { return pendingOrders; }
vector<shared_ptr<Order>> OrderQueue::getPreparingOrders() const { return preparingOrders; }
vector<shared_ptr<Order>> OrderQueue::getCompletedOrders() const { return completedOrders; }

int OrderQueue::getPendingCount() const { return pendingOrders.size(); }
int OrderQueue::getPreparingCount() const { return preparingOrders.size(); }
int OrderQueue::getCompletedCount() const { return completedOrders.size(); }
int OrderQueue::getTotalCount() const { 
    return pendingOrders.size() + preparingOrders.size() + completedOrders.size(); 
}
