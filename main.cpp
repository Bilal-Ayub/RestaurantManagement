#include <iostream>
#include <memory>
#include <vector>
#include "MenuItem.h"
#include "Appetizer.h"
#include "MainCourse.h"
#include "Dessert.h"
#include "Beverage.h"
#include "Order.h"
#include "OrderQueue.h"
#include "Customer.h"
#include "Kitchen.h"
#include "Manager.h"
#include "Bill.h"

using namespace std;

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "   RESTAURANT MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Customer Interface" << endl;
    cout << "2. Kitchen Interface" << endl;
    cout << "3. Manager Interface" << endl;
    cout << "4. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

void customerInterface(Customer& customer, Manager& manager, OrderQueue& orderQueue) {
    int choice;
    do {
        cout << "\n=== CUSTOMER MENU ===" << endl;
        cout << "1. View Menu" << endl;
        cout << "2. Add Item to Cart" << endl;
        cout << "3. View Cart" << endl;
        cout << "4. Remove Item from Cart" << endl;
        cout << "5. Place Order" << endl;
        cout << "6. View Order History" << endl;
        cout << "7. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                manager.displayMenu();
                break;
            }
            case 2: {
                cout << "\nEnter item name: ";
                cin.ignore();
                string itemName;
                getline(cin, itemName);
                
                auto item = manager.findMenuItem(itemName);
                if (item != nullptr) {
                    cout << "Enter special instructions (or press Enter to skip): ";
                    string instructions;
                    getline(cin, instructions);
                    customer.addItemToCart(item, instructions);
                    cout << "Item added to cart!" << endl;
                } else {
                    cout << "Item not found." << endl;
                }
                break;
            }
            case 3: {
                customer.viewCart();
                break;
            }
            case 4: {
                cout << "Enter item index to remove: ";
                int index;
                cin >> index;
                customer.removeItemFromCart(index - 1);
                cout << "Item removed." << endl;
                break;
            }
            case 5: {
                auto order = customer.placeOrder();
                if (order != nullptr) {
                    orderQueue.addOrder(order);
                    
                    // Generate and display bill
                    Bill bill(order);
                    bill.displayBill();
                }
                break;
            }
            case 6: {
                customer.viewOrderHistory();
                break;
            }
        }
    } while (choice != 7);
}

void kitchenInterface(Kitchen& kitchen) {
    int choice;
    do {
        cout << "\n=== KITCHEN MENU ===" << endl;
        cout << "1. View Pending Orders" << endl;
        cout << "2. View Preparing Orders" << endl;
        cout << "3. View Completed Orders" << endl;
        cout << "4. Start Preparing Order" << endl;
        cout << "5. Complete Order" << endl;
        cout << "6. View Kitchen Status" << endl;
        cout << "7. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                kitchen.viewPendingOrders();
                break;
            }
            case 2: {
                auto preparingOrders = kitchen.getOrderQueue()->getPreparingOrders();
                cout << "\n=== PREPARING ORDERS ===" << endl;
                if (preparingOrders.empty()) {
                    cout << "No orders being prepared." << endl;
                } else {
                    for (const auto& order : preparingOrders) {
                        order->displayOrder();
                    }
                }
                break;
            }
            case 3: {
                auto completedOrders = kitchen.getOrderQueue()->getCompletedOrders();
                cout << "\n=== COMPLETED ORDERS ===" << endl;
                if (completedOrders.empty()) {
                    cout << "No completed orders." << endl;
                } else {
                    for (const auto& order : completedOrders) {
                        order->displayOrder();
                    }
                }
                break;
            }
            case 4: {
                cout << "Enter order ID to start preparing: ";
                int orderId;
                cin >> orderId;
                kitchen.startPreparingOrder(orderId);
                break;
            }
            case 5: {
                cout << "Enter order ID to mark as complete: ";
                int orderId;
                cin >> orderId;
                kitchen.completeOrder(orderId);
                break;
            }
            case 6: {
                kitchen.displayKitchenStatus();
                break;
            }
        }
    } while (choice != 7);
}

void managerInterface(Manager& manager) {
    int choice;
    do {
        cout << "\n=== MANAGER MENU ===" << endl;
        cout << "1. View Full Menu" << endl;
        cout << "2. View Menu by Category" << endl;
        cout << "3. Add Menu Item" << endl;
        cout << "4. Remove Menu Item" << endl;
        cout << "5. Update Item Price" << endl;
        cout << "6. Update Item Availability" << endl;
        cout << "7. View Sales Report" << endl;
        cout << "8. View Order History" << endl;
        cout << "9. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                manager.displayMenu();
                break;
            }
            case 2: {
                cout << "\nCategories: Appetizer, Main Course, Dessert, Beverage" << endl;
                cout << "Enter category: ";
                cin.ignore();
                string category;
                getline(cin, category);
                manager.displayMenuByCategory(category);
                break;
            }
            case 3: {
                cout << "\nAdd Menu Item:" << endl;
                cout << "Select type: 1-Appetizer, 2-MainCourse, 3-Dessert, 4-Beverage: ";
                int type;
                cin >> type;
                cin.ignore();
                
                cout << "Enter name: ";
                string name;
                getline(cin, name);
                
                cout << "Enter description: ";
                string desc;
                getline(cin, desc);
                
                cout << "Enter base price: ";
                double price;
                cin >> price;
                
                shared_ptr<MenuItem> item;
                switch (type) {
                    case 1:
                        item = make_shared<Appetizer>(name, desc, price);
                        break;
                    case 2:
                        item = make_shared<MainCourse>(name, desc, price);
                        break;
                    case 3:
                        item = make_shared<Dessert>(name, desc, price);
                        break;
                    case 4:
                        item = make_shared<Beverage>(name, desc, price);
                        break;
                }
                
                if (item) {
                    manager.addMenuItem(item);
                }
                break;
            }
            case 4: {
                cout << "Enter item name to remove: ";
                cin.ignore();
                string name;
                getline(cin, name);
                manager.removeMenuItem(name);
                break;
            }
            case 5: {
                cout << "Enter item name: ";
                cin.ignore();
                string name;
                getline(cin, name);
                cout << "Enter new price: ";
                double price;
                cin >> price;
                manager.updateMenuItemPrice(name, price);
                break;
            }
            case 6: {
                cout << "Enter item name: ";
                cin.ignore();
                string name;
                getline(cin, name);
                cout << "Set available (1-Yes, 0-No): ";
                int avail;
                cin >> avail;
                manager.updateMenuItemAvailability(name, avail == 1);
                break;
            }
            case 7: {
                manager.viewSalesReport();
                break;
            }
            case 8: {
                manager.viewOrderHistory();
                break;
            }
        }
    } while (choice != 9);
}

int main() {
    cout << "========================================" << endl;
    cout << "   INITIALIZING RESTAURANT SYSTEM" << endl;
    cout << "========================================" << endl;
    
    // Create order queue
    OrderQueue orderQueue;
    
    // Create manager and initialize menu
    Manager manager("John Manager", "MGR001", &orderQueue);
    
    cout << "\nLoading menu items..." << endl;
    
    // Add Appetizers
    manager.addMenuItem(make_shared<Appetizer>("Mozzarella Sticks", "Crispy breaded cheese sticks", 8.99, true, "", "Medium", "Mild"));
    manager.addMenuItem(make_shared<Appetizer>("Buffalo Wings", "Spicy chicken wings with blue cheese", 12.99, true, "", "Large", "Hot"));
    manager.addMenuItem(make_shared<Appetizer>("Bruschetta", "Toasted bread with tomatoes and basil", 7.99, true, "", "Small", "Mild"));
    manager.addMenuItem(make_shared<Appetizer>("Calamari", "Fried squid rings with marinara", 11.99, true, "", "Medium", "Medium"));
    
    // Add Main Courses
    auto burger = make_shared<MainCourse>("Classic Burger", "Juicy beef patty with lettuce and tomato", 14.99, true, "", "Grilled", "Medium");
    burger->addTopping("Cheese", 1.50);
    burger->addTopping("Bacon", 2.00);
    manager.addMenuItem(burger);
    
    auto pasta = make_shared<MainCourse>("Fettuccine Alfredo", "Creamy pasta with parmesan", 16.99, true, "", "Baked", "Large");
    pasta->addTopping("Chicken", 3.00);
    pasta->addTopping("Mushrooms", 1.50);
    manager.addMenuItem(pasta);
    
    manager.addMenuItem(make_shared<MainCourse>("Grilled Salmon", "Atlantic salmon with herbs", 22.99, true, "", "Grilled", "Medium"));
    manager.addMenuItem(make_shared<MainCourse>("Margherita Pizza", "Classic tomato, mozzarella, and basil", 13.99, true, "", "Baked", "Large"));
    
    // Add Desserts
    manager.addMenuItem(make_shared<Dessert>("Chocolate Lava Cake", "Warm chocolate cake with molten center", 7.99, true, "", false, "High", false));
    manager.addMenuItem(make_shared<Dessert>("Tiramisu", "Italian coffee-flavored dessert", 8.99, true, "", false, "Medium", false));
    manager.addMenuItem(make_shared<Dessert>("Cheesecake", "New York style cheesecake", 6.99, true, "", true, "High", false));
    manager.addMenuItem(make_shared<Dessert>("Ice Cream Sundae", "Vanilla ice cream with toppings", 5.99, true, "", true, "High", true));
    
    // Add Beverages
    manager.addMenuItem(make_shared<Beverage>("Coffee", "Freshly brewed coffee", 2.99, true, "", "Medium", "Hot", true));
    manager.addMenuItem(make_shared<Beverage>("Iced Tea", "Refreshing iced tea", 2.49, true, "", "Large", "Cold", false));
    manager.addMenuItem(make_shared<Beverage>("Coca Cola", "Classic soft drink", 2.99, true, "", "Medium", "Cold", true));
    manager.addMenuItem(make_shared<Beverage>("Orange Juice", "Freshly squeezed orange juice", 3.99, true, "", "Small", "Cold", false));
    manager.addMenuItem(make_shared<Beverage>("Cappuccino", "Espresso with steamed milk", 4.99, true, "", "Small", "Hot", true));
    
    cout << "Menu loaded with " << manager.getMenu().size() << " items!" << endl;
    
    // Create kitchen
    Kitchen kitchen("Main Kitchen", &orderQueue);
    
    // Create a sample customer
    Customer customer("Alice Johnson", "555-1234", "alice@email.com");
    
    cout << "\n*** Pre-loading sample orders for demonstration ***\n" << endl;
    
    // Create and place a sample order
    Customer sampleCustomer1("Bob Smith", "555-5678", "bob@email.com");
    sampleCustomer1.startNewOrder();
    sampleCustomer1.addItemToCart(manager.findMenuItem("Buffalo Wings"), "Extra crispy");
    sampleCustomer1.addItemToCart(manager.findMenuItem("Classic Burger"), "No onions");
    sampleCustomer1.addItemToCart(manager.findMenuItem("Coca Cola"), "");
    auto order1 = sampleCustomer1.placeOrder();
    if (order1) orderQueue.addOrder(order1);
    
    // Create another sample order
    Customer sampleCustomer2("Carol Davis", "555-9999", "carol@email.com");
    sampleCustomer2.startNewOrder();
    sampleCustomer2.addItemToCart(manager.findMenuItem("Margherita Pizza"), "Extra cheese");
    sampleCustomer2.addItemToCart(manager.findMenuItem("Iced Tea"), "");
    sampleCustomer2.addItemToCart(manager.findMenuItem("Tiramisu"), "");
    auto order2 = sampleCustomer2.placeOrder();
    if (order2) orderQueue.addOrder(order2);
    
    // Move one order through the workflow for demo
    if (order1) {
        orderQueue.moveToPreparation(order1->getOrderId());
        orderQueue.markAsComplete(order1->getOrderId());
    }
    
    cout << "\nSample data loaded! 2 orders created (1 completed, 1 pending)" << endl;
    cout << "\nStarting main system...\n" << endl;
    
    // Main program loop
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                customerInterface(customer, manager, orderQueue);
                break;
            case 2:
                kitchenInterface(kitchen);
                break;
            case 3:
                managerInterface(manager);
                break;
            case 4:
                cout << "\nThank you for using the Restaurant Management System!" << endl;
                cout << "Goodbye!\n" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
