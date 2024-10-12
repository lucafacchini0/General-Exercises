#include <iostream>
#include <cstdint>
#include <string>

using std::string;

class Category {
public:
    Category(const string &name, const string &description) 
    : name(name), description(description) {}

    void display() const {
        std::cout << "Category Name: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
    }

private:
    const string name;
    const string description;
};

class Product {
public:
    Product(const string &name, const float price, const int stock, Category *category) 
    : name(name), price(price), stock(stock), category(category) {}

    void display() const {
        std::cout << "Product Name: " << name << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        category->display(); 
    }

private:
    const string name;
    const float price;
    const int stock;
    Category *category; // I will pass this pointer from the constructor call in main()
};

int main() {
    // A category object will be created on the heap, a pointer to that in the stack.
    Category *electronics = new Category("Electronics", "IT Devices.");
    Category *kitchen = new Category("Kitchen", "Kitchen Devices.");

    Product oven("Oven", 1000, 5, electronics);
    oven.display(); 

    delete electronics;
    delete kitchen;

    return 0;
}
