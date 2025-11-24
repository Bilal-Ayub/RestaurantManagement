#ifndef BILL_H
#define BILL_H

#include "Order.h"
#include <memory>
#include <string>
#include <ctime>

class Bill {
private:
    static int nextBillId;
    int billId;
    std::shared_ptr<Order> order;
    double taxRate;
    std::time_t generatedTime;
    bool isPaid;

public:
    // Constructor
    Bill(std::shared_ptr<Order> order, double taxRate = 0.13);
    
    // Calculate bill amounts
    double getSubtotal() const;
    double getTaxAmount() const;
    double getTotal() const;
    
    // Generate and display bill
    void generateBill() const;
    void displayBill() const;
    
    // Payment management
    void markAsPaid();
    bool getPaymentStatus() const;
    
    // Getters
    int getBillId() const;
    std::shared_ptr<Order> getOrder() const;
    double getTaxRate() const;
    std::time_t getGeneratedTime() const;
    
    // Setters
    void setTaxRate(double rate);
};

#endif
