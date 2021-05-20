#include <iostream>

class Example {
private:
    int a = 2;
    double b = 2.0;
    int c = 3;

public:
    Example();
    void aShow();
    void bShow();
    void cShow();
    int getC();
};

Example::Example() {

}

void Example::aShow() {
    std::cout << this->a << std::endl;
}

void Example::bShow() {
    std::cout << this->b << std::endl;
}

void Example::cShow() {
    std::cout << this->c << std::endl;
}

int Example::getC() {
    return this->c;
}

class ExampleA {
private:
    int i = 7;

public:
    ExampleA();
    void showExA(int a);
};

ExampleA::ExampleA() {

}

void ExampleA::showExA(int a) {
    std::cout << this->i * a << std::endl;
}