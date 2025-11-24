#include "Bill.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int Bill::nextBillId = 5000;

Bill::Bill(shared_ptr<Order> order, double taxRate)
    : billId(nextBillId++), order(order), taxRate(taxRate),
      generatedTime(std::time(nullptr)), isPaid(false) {}

double Bill::getSubtotal() const {
    return (order != nullptr) ? order->getSubtotal() : 0.0;
}

double Bill::getTaxAmount() const {
    return getSubtotal() * taxRate;
}

double Bill::getTotal() const {
    return getSubtotal() + getTaxAmount();
}

void Bill::generateBill() const {
    displayBill();
}

void Bill::displayBill() const {
    if (order == nullptr) {
        cout << "No order associated with this bill." << endl;
        return;
    }
    
    cout << "\n========================================" << endl;
    cout << "              BILL #" << billId << endl;
    cout << "========================================" << endl;
    cout << "Order ID: " << order->getOrderId() << endl;
    cout << "Customer: " << order->getCustomerName() << endl;
    
    // Convert time to string
    char timeStr[100];
    std::time_t temp = generatedTime;
    std::tm* timeinfo = std::localtime(&temp);
    std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeinfo);
    cout << "Date/Time: " << timeStr << endl;
    cout << "----------------------------------------" << endl;
    
    // Display items
    auto items = order->getItems();
    auto instructions = order->getSpecialInstructions();
    
    cout << "\nITEMS:" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << (i + 1) << ". " << items[i]->getName() 
                  << " - $" << fixed << setprecision(2) 
                  << items[i]->getPrice() << endl;
        
        if (!instructions[i].empty()) {
            cout << "   Note: " << instructions[i] << endl;
        }
    }
    
    cout << "----------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal:        $" << setw(10) << getSubtotal() << endl;
    cout << "Tax (" << setprecision(0) << (taxRate * 100) << "%):      $" 
              << setprecision(2) << setw(10) << getTaxAmount() << endl;
    cout << "========================================" << endl;
    cout << "TOTAL:           $" << setw(10) << getTotal() << endl;
    cout << "========================================" << endl;
    cout << "Payment Status: " << (isPaid ? "PAID" : "UNPAID") << endl;
    cout << "========================================\n" << endl;
}

void Bill::markAsPaid() {
    isPaid = true;
    cout << "Bill #" << billId << " has been marked as paid." << endl;
}

bool Bill::getPaymentStatus() const {
    return isPaid;
}

// Getters
int Bill::getBillId() const { return billId; }
shared_ptr<Order> Bill::getOrder() const { return order; }
double Bill::getTaxRate() const { return taxRate; }
std::time_t Bill::getGeneratedTime() const { return generatedTime; }

// Setters
void Bill::setTaxRate(double rate) { this->taxRate = rate; }
