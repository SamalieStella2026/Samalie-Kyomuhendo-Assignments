#include <iostream>
#include <iomanip>
#include <string>

class Rectangle {
private:
    double width;
    double length;

public:
    // Default constructor: 1 x 1 rectangle
    Rectangle() : width(1.0), length(1.0) {}

    // Parameterised constructor (uses setters so values are validated)
    Rectangle(double w, double l) : width(1.0), length(1.0) {
        setWidth(w);
        setLength(l);
    }

    // Getters
    double getWidth() const { return width; }
    double getLength() const { return length; }

    // Setters: ignore non-positive values
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            std::cout << "Invalid width (" << w << "): must be positive. Width unchanged.\n";
        }
    }

    void setLength(double l) {
        if (l > 0) {
            length = l;
        } else {
            std::cout << "Invalid length (" << l << "): must be positive. Length unchanged.\n";
        }
    }

    // Calculations
    double area() const { return width * length; }
    double perimeter() const { return 2 * (width + length); }
};

void printRectangle(const std::string& name, const Rectangle& r) {
    std::cout << name << ": width = " << r.getWidth()
              << ", length = " << r.getLength()
              << ", area = " << r.area()
              << ", perimeter = " << r.perimeter() << "\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Default-constructed rectangle
    Rectangle r1;
    std::cout << "--- Default rectangle ---\n";
    printRectangle("r1", r1);

    // Set dimensions with setters, read them back with getters
    r1.setWidth(5.0);
    r1.setLength(8.5);
    std::cout << "\n--- After setting r1 to 5.0 x 8.5 ---\n";
    std::cout << "Width:  " << r1.getWidth() << "\n";
    std::cout << "Length: " << r1.getLength() << "\n";
    std::cout << "Area:      " << r1.area() << "\n";
    std::cout << "Perimeter: " << r1.perimeter() << "\n";

    //Rectangle created with dimensions
    Rectangle r2(3.0, 4.0);
    std::cout << "\n--- Rectangle created with 3.0 x 4.0 ---\n";
    printRectangle("r2", r2);

    //  Modify an existing rectangle
    r2.setWidth(10.0);
    std::cout << "\n--- r2 after changing width to 10.0 ---\n";
    printRectangle("r2", r2);

    //  Invalid input is rejected
    std::cout << "\n--- Invalid input ---\n";
    r2.setLength(-2.0);
    printRectangle("r2", r2);

    //  Several rectangles in an array
    std::cout << "\n--- Array of rectangles ---\n";
    Rectangle shapes[3] = { Rectangle(2, 3), Rectangle(6, 6), Rectangle(1.5, 9) };
    for (int i = 0; i < 3; ++i) {
        printRectangle("shape[" + std::to_string(i) + "]", shapes[i]);
    }

    return 0;
}
