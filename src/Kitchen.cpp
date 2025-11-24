#include "Kitchen.h"
#include <iostream>

using namespace std;

Kitchen::Kitchen(const string& kitchenName, OrderQueue* orderQueue)
    : kitchenName(kitchenName), orderQueue(orderQueue) {}

void Kitchen::viewPendingOrders() const {
    if (orderQueue != nullptr) {
        std::cout << "\n=== " << kitchenName << " - PENDING ORDERS ===" << std::endl;
        orderQueue->displayPendingOrders();
    } else {
        std::cout << "No order queue available." << std::endl;
    }
}

void Kitchen::startPreparingOrder(int orderId) {
    if (orderQueue != nullptr) {
        orderQueue->moveToPreparation(orderId);
        std::cout << "Order #" << orderId << " moved to preparation." << std::endl;
    } else {
        std::cout << "No order queue available." << std::endl;
    }
}

void Kitchen::completeOrder(int orderId) {
    if (orderQueue != nullptr) {
        orderQueue->markAsComplete(orderId);
        std::cout << "Order #" << orderId << " marked as ready!" << std::endl;
    } else {
        std::cout << "No order queue available." << std::endl;
    }
}

void Kitchen::viewOrderDetails(int orderId) const {
    if (orderQueue != nullptr) {
        auto order = orderQueue->findOrder(orderId);
        if (order != nullptr) {
            order->displayOrder();
        } else {
            std::cout << "Order #" << orderId << " not found." << std::endl;
        }
    } else {
        std::cout << "No order queue available." << std::endl;
    }
}

void Kitchen::displayKitchenStatus() const {
    if (orderQueue != nullptr) {
        std::cout << "\n=== " << kitchenName << " STATUS ===" << std::endl;
        std::cout << "Pending Orders: " << orderQueue->getPendingCount() << std::endl;
        std::cout << "Preparing Orders: " << orderQueue->getPreparingCount() << std::endl;
        std::cout << "Completed Orders: " << orderQueue->getCompletedCount() << std::endl;
        std::cout << "Total Orders: " << orderQueue->getTotalCount() << std::endl;
    } else {
        std::cout << "No order queue available." << std::endl;
    }
}

// Getters
string Kitchen::getKitchenName() const { return kitchenName; }
OrderQueue* Kitchen::getOrderQueue() const { return orderQueue; }

// Setters
void Kitchen::setKitchenName(const string& name) { this->kitchenName = name; }
void Kitchen::setOrderQueue(OrderQueue* queue) { this->orderQueue = queue; }
