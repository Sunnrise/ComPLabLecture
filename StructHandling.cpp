#include <iostream>
#include <limits>

#define MAX_PRODUCTS 3// Change the value of MAX_PRODUCTS to 5 for testing

using namespace std;

struct Product {
    char name[50];
    int quantity;
    float price;
};

void inputProduct(Product& product, int index) {
    cout << "Enter the name of product #" << index << ": ";
    cin.getline(product.name, 50);
    cout << "Enter the quantity of product #" << index << ": ";
    cin >> product.quantity;
    cout << "Enter the price of product #" << index << ": ";
    cin >> product.price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
}

void printProduct(const Product& product) {
    cout << "Name: " << product.name << ", Quantity: " << product.quantity << ", Price: $" << product.price << endl;
}

int main() {
    Product products[MAX_PRODUCTS];

    // Input products
    for (int i = 0; i < MAX_PRODUCTS; ++i) {
        cout << "--------------------------------------------------------" << endl;
        inputProduct(products[i], i + 1);
    }

    // Find cheapest and most expensive products
    int cheapestIndex = 0;
    int expensiveIndex = 0;
    float totalPrice = 0.0;

    for (int i = 0; i < MAX_PRODUCTS; ++i) {
        totalPrice += products[i].quantity * products[i].price;
        if (products[i].price < products[cheapestIndex].price) {
            cheapestIndex = i;
        }
        if (products[i].price > products[expensiveIndex].price) {
            expensiveIndex = i;
        }
    }

    // Output results
    cout << "--------------------------------------------------------" << endl;
    cout << "The cheapest product is: " << products[cheapestIndex].name << endl;
    cout << "The most expensive product is: " << products[expensiveIndex].name << endl;
    cout << "The total value is: " << totalPrice << endl;

    return 0;
}
