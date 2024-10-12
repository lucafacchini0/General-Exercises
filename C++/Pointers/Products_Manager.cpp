#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// Class representing a category for products
class Category {
public:
    // Constructor initializes the category with a name and description
    Category(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {}

    // Method to display category details
    void displayDetails() const {
        std::cout << "Category: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
    }

    // Getter for category name, marked as [[nodiscard]] to indicate that the return value should not be ignored
    [[nodiscard]] const std::string& getName() const { return name; }

private:
    const std::string name;         // Name of the category (immutable)
    const std::string description;  // Description of the category (immutable)
};

// Class representing a product
class Product {
public:
    Product(std::string name, float price)
        : name(std::move(name)), price(price), stock(0) {}

    Product(std::string name, float price, int stock)
        : name(std::move(name)), price(price), stock(stock) {}

    Product(std::string name, float price, int stock, std::shared_ptr<Category> category)
        : name(std::move(name)), price(price), stock(stock) {
        addCategory(category); // Use of shared_ptr allows shared ownership of the category
    }

    // Getters for product attributes
    [[nodiscard]] const std::string& getName() const { return name; }
    [[nodiscard]] float getPrice() const { return price; }
    [[nodiscard]] int getStock() const { return stock; }

    // Method to display product details, including categories
    void displayDetails() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;

        // Check if product has associated categories
        if (!categories.empty()) {
            std::cout << "Categories: " << std::endl;
            // Iterate through each category and display its details
            for (const auto& category : categories) {
                category->displayDetails(); // Call to displayDetails on shared_ptr
            }
        } else {
            std::cout << "Categories: None" << std::endl; // Indicates no categories added
        }
    }

    void setPrice(float newPrice) { price = newPrice; }
    void addStock(int amount) { stock += amount; }
    void removeStock(int amount) { stock = (stock < amount) ? 0 : stock - amount; }

    // Method to add a category to the product
    void addCategory(std::shared_ptr<Category> category) {
        // Check if the category already exists in the product's category list to avoid duplicates
        for (const auto& cat : categories) {
            if (cat->getName() == category->getName()) {
                return; // Category already added, exit the function early
            }
        }
        // Use of push_back to add the shared_ptr to the vector of categories
        categories.push_back(std::move(category));
    }

private:
    const std::string name;                             // Name of the product (immutable)
    float price;                                        // Price of the product
    int stock;                                          // Stock quantity of the product
    std::vector<std::shared_ptr<Category>> categories; // Categories associated with the product (using shared_ptr for shared ownership)
};

int main() {
    // Create category objects using shared_ptr for automatic memory management
    std::shared_ptr<Category> electronics = std::make_shared<Category>("Electronics", "Electronic stuff, yay!");
    std::shared_ptr<Category> kitchen = std::make_shared<Category>("Kitchen", "You know, stuff that has to be in a kitchen.");
    std::shared_ptr<Category> gaming = std::make_shared<Category>("Gaming", "You're gonna beat Fortnite!");

    // Create a product and add categories later
    Product headphones("Headphones Barracuda", 399.99, 50);
    headphones.addCategory(electronics);
    headphones.addCategory(gaming);

    headphones.displayDetails();

    return 0;
}
