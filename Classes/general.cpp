#include <iostream>
#include <string>
#include <cmath>

using std::string;

const double PI = 3.14159; // Define PI as a constant

class Rettangolo {
private:
    double lunghezza;
    double altezza;

public:
    // Constructor
    Rettangolo(double lunghezza, double altezza) : lunghezza(lunghezza), altezza(altezza) {}

    // Function to calculate area
    double area() {
        return lunghezza * altezza;
    }

    // Function to calculate perimeter
    double perimeter() {
        return 2 * (lunghezza + altezza);
    }
};

class Cerchio {
private:
    double radius;

public:
    // Default constructor
    Cerchio() : radius(0) {}

    // Constructor with parameter
    Cerchio(double radius) : radius(radius) {}

    // Function to change radius
    void changeRadius(double radius) {
        this->radius = radius;
    }

    // Function to calculate circumference
    double circumference() {
        return PI * radius * 2;
    }

    // Function to calculate area
    double area() {
        return PI * radius * radius;
    }
};

class Punto {
private:
    double x;
    double y;

public:
    // Default constructor
    Punto() : x(0), y(0) {}

    // Constructor with parameters
    Punto(double x, double y) : x(x), y(y) {}

    // Function to set coordinates
    void coordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }

    // Function to print coordinates
    void print() {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }

    // Function to calculate distance from origin
    double originDistance() {
        return sqrt(x * x + y * y);
    }
};

class Student {
    private:
        string name;
        int matricola;
        int year;

    public:
        Student() : name(""),matricola(0), year(0) {}

        Student(string name, int matricola, int year) {
            this->name = name;
            this->matricola = matricola;
            this->year = year;
        }

        void setName() {
            this->name = name;
        }
        void setMatricola() {

            this->matricola = matricola;
        }

        void setYear() {
            this-> year = year;
        }

        void getInfo() {

            std::cout << "Name: " << name << std::endl;
            std::cout << "Matricola: " << matricola << std::endl;
            std::cout << "Year: " << year << std::endl;
        }

};



int main() {
    // Create a Punto object
    Punto punto1;
    punto1.coordinates(30, 40);
    punto1.print();
    std::cout << "Distance from origin: " << punto1.originDistance() << std::endl;

    // Create a Cerchio object
    Cerchio cerchio1(50);
    std::cout << "Area of the circle: " << cerchio1.area() << std::endl;
    std::cout << "Circumference of the circle: " << cerchio1.circumference() << std::endl;

    // Example of Rettangolo
    Rettangolo rettangolo1(10, 5);
    std::cout << "Area of the rectangle: " << rettangolo1.area() << std::endl;
    std::cout << "Perimeter of the rectangle: " << rettangolo1.perimeter() << std::endl;

    // Example of Student
    Student student1("Luca", 1855, 2009);
    student1.getInfo();

    return 0;
}
