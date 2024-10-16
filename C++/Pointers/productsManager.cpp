#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// Class representing a category for products
class Category {
public:
    // Constructor to initialize the category with a name and description
    Category(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {}

    // Method to display the details of the category
    void displayDetails() const {
        std::cout << "Category: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
    }

    // Getter for the category name
    // [[nodiscard]] indicates that the return value should not be ignored
    [[nodiscard]] const std::string& getName() const { return name; }

private:
    const std::string name;         // Name of the category (immutable)
    const std::string description;  // Description of the category (immutable)
};

// Class representing a product
class Product {
public:
    // Constructor that initializes product with name and price, stock defaults to 0
    Product(std::string name, float price)
        : name(std::move(name)), price(price), stock(0) {}

    // Constructor that initializes product with name, price, and stock
    Product(std::string name, float price, int stock)
        : name(std::move(name)), price(price), stock(stock) {}

    // Constructor that initializes product with name, price, stock, and a category
    Product(std::string name, float price, int stock, std::shared_ptr<Category> category)
        : name(std::move(name)), price(price), stock(stock) {
        addCategory(category); // Add the category to the product
    }

    // Getters for product attributes
    [[nodiscard]] const std::string& getName() const { return name; }
    [[nodiscard]] float getPrice() const { return price; }
    [[nodiscard]] int getStock() const { return stock; }

    // Method to display the details of the product, including its categories
    void displayDetails() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;

        // Check if there are any categories associated with the product
        if (!categories.empty()) {
            std::cout << "Categories: " << std::endl;
            // Display details of each category
            for (const auto& category : categories) {
                category->displayDetails();
            }
        } else {
            std::cout << "Categories: None" << std::endl;
        }
    }

    // Method to set a new price for the product
    void setPrice(float newPrice) { price = newPrice; }

    // Method to add stock to the product
    void addStock(int amount) { stock += amount; }

    // Method to remove stock, ensuring stock doesn't go below 0
    void removeStock(int amount) { stock = (stock < amount) ? 0 : stock - amount; }

    // Method to add a category to the product
    void addCategory(std::shared_ptr<Category> category) {
        // Avoid adding duplicate categories
        for (const auto& cat : categories) {
            if (cat->getName() == category->getName()) {
                return; // If category already exists, do nothing
            }
        }
        // Add the category to the list of categories
        categories.push_back(std::move(category));
    }

private:
    const std::string name;                             // Name of the product (immutable)
    float price;                                        // Price of the product
    int stock;                                          // Quantity in stock
    std::vector<std::shared_ptr<Category>> categories;  // Categories associated with the product
};

int main() {
    // Create category objects using shared_ptr for automatic memory management
    std::shared_ptr<Category> electronics = std::make_shared<Category>("Electronics", "Electronic stuff, yay!");
    std::shared_ptr<Category> kitchen = std::make_shared<Category>("Kitchen", "You know, stuff that has to be in a kitchen.");
    std::shared_ptr<Category> gaming = std::make_shared<Category>("Gaming", "You're gonna beat Fortnite!");

    // Create a product and later add categories to it
    Product headphones("Headphones Barracuda", 399.99, 50);
    headphones.addCategory(electronics);
    headphones.addCategory(gaming);

    // Display the details of the product, including its categories
    headphones.displayDetails();

    return 0; // End of program
}

/*
    Memory Explanation:

    1. Category Creation:
       - 'electronics', 'kitchen', and 'gaming' are created on the heap using std::make_shared.
       - This ensures shared ownership of categories via reference counting.

    2. Product Creation:
       - 'headphones' is created on the stack in 'main' with initial stock and price values.
       - Memory for the name and category pointers is allocated.

    3. Function Calls - addCategory and displayDetails:
       - `addCategory` checks for duplicates and adds shared category pointers.
       - `displayDetails` prints product and associated category details.

    4. Memory Release:
       - Shared ownership ensures that categories are deallocated when the last reference to them is released.
       - The stack memory for 'headphones' and the shared_ptrs in 'categories' is automatically cleaned up.
*/
