// factoryDesign.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

/**************************************************/
class Product {
    public:
        virtual void productSolution() const = 0;
};

class Product1 : public Product {
    public:
        ~Product1(){}
        void productSolution() const override {
            cout << "\nProduct 1 created";
        }
};

class Product2 : public Product {
    public:
        void productSolution() const override {
            cout << "\nProduct 2 created";
        }
};
/**************************************************/

/**************************************************/
class Creator {
    public:
        virtual Product* createProduct() const = 0;

        // created and produced product via Creator
        void solution() {
            Product* product = this->createProduct();
            product->productSolution();
        }
};

class Creator1 : public Creator {
    Product* createProduct() const override {
        return new Product1;
    }
};

class Creator2 : public Creator {
    Product* createProduct() const override {
        return new Product2;
    }
};
/**************************************************/

int main()
{
    std::cout << "Hello World!\n";
    Creator* creator = new Creator1();
    creator->solution();

    creator = new Creator2();
    creator->solution();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
