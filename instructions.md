CS/CE 224/272
Object Oriented Programming and Design Methodologies

Project Title Restaurant Order Management System
Team Title (as on Canvas) Project Group 35

1. Introduction

The Restaurant Order Management System is a comprehensive application designed to streamline restaurant operations through three integrated user interfaces. The system allows customers to browse menus and place orders, enables kitchen staff to manage order preparation efficiently, and provides managers with tools for menu management and sales reporting.

Built using Object-Oriented Programming principles and TGUI library, the application demonstrates key OOP concepts including inheritance, polymorphism, composition, and aggregation through a network of 10+ interconnected classes. The system features real-time order updates, customizable menu items and automated billing making it a practical solution for modern restaurant management while serving as an excellent demonstration of advanced programming concepts.

2. Application Details

2.1 User Roles:
The application supports three distinct user types, each with a dedicated interface:

Customer Role:
• Primary users who interact with the menu and place orders
• Can browse menu items by category
• Customize orders with toppings, size options, and special instructions
• View shopping cart and order totals in real-time
• Place and confirm orders

Kitchen Staff Role:
• Receive and view incoming orders in a queue format
• See detailed order information including items, customizations, and special instructions
• Update order status (Received → Preparing → Ready)

Manager Role:
• Full administrative access to the system
• Add, edit, and remove menu items
• Update prices and availability
• View sales statistics
• Access order history and analytics

2.2 Menu System
The menu is organized into four main categories:

1. Appetizers - Starters and small plates with portion sizes and spice levels
2. Main Courses - Primary dishes with customizable toppings and preparation options
3. Desserts - Sweet items with dietary information (nuts, sugar levels)
4. Beverages - Drinks with size variations (Small/Medium/Large) and temperature options (Hot/Cold)
   Each menu item includes:
   • Item name and description
   • Base price
   • Category classification
   • Availability status
   • Image/icon representation
   • Customization options (where applicable)

2.3 Order Management

Order Creation Process:

1. Customer selects items from menu
2. Customizes items (size, toppings, special instructions)
3. Items added to shopping cart
4. Cart displays running total with tax calculation
5. Customer reviews and confirms order
6. Order assigned unique ID and timestamp
   Order Processing Workflow:
7. New order appears in Kitchen Display System
8. Kitchen staff marks order as "Preparing"
9. Progress tracked with timer
10. Order marked as "Ready" when complete
11. Customer notification (visual/audio)
12. Order moved to completed queue

2.4 Customization Engine
The system supports flexible item customization:
Size Options:
• Small, Medium, Large (affects price)
• Applied to beverages and certain main courses
Toppings/Add-ons:
• Multiple selections allowed
• Each topping has individual price
• Real-time price update as selections change
Special Instructions:
• Free-text field for custom requests
• Examples: "Extra crispy", "No onions", "Light sauce"
• Displayed prominently in kitchen view

2.5 Billing System
Automated billing with the following components:
• Subtotal: Sum of all item prices including customizations
• Tax Calculation: Configurable tax rate (default 13%)
• Total: Final amount due
• Bill Generation: Itemized receipt with order breakdown

2.6 Reporting and Analytics
Sales Reports:
• Daily revenue totals
• Number of orders processed
• Average order value
• Category wise Sales breakdown

Core Classes:

1. MenuItem (Abstract Base Class)
2. Appetizer (inherits MenuItem)
3. MainCourse (inherits MenuItem)
4. Dessert (inherits MenuItem)
5. Beverage (inherits MenuItem)
6. Order
7. OrderQueue
8. Customer
9. Kitchen
10. Manager
11. Bill

Class Relationships:
Inheritance Relationships (IS-A):
• Appetizer MenuItem
• MainCourse MenuItem
• Dessert MenuItem
• Beverage MenuItem

Composition (HAS-A / Strong Ownership):
• Order —→ MenuItem (Order contains MenuItems)
• Customer —→ Order (Customer has current Order)

Aggregation (HAS-A / Weak Ownership):
• OrderQueue —→ Order (OrderQueue manages Orders)
• Kitchen —→ Order (Kitchen works with Orders)

Association:
• Customer ———→ Order (Customer places Order)
• Manager ———→ MenuItem (Manager manages MenuItems)
• Bill ———→ Order (Bill is generated from Order)

3. UML Diagram

4. Application Screens

Screen 2: Customer Menu Browsing Screen

Screen 3: Order Customization Screen

Screen 5: Kitchen Display System

Screen 6: Manager Dashboard
