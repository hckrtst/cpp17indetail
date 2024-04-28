#include <iostream>

struct Test {
    Test() {
        std::cout << "ctor\n";
    }

    Test(const Test&) {
        std::cout << "copy ctor" << std::endl;
    }

    Test operator=(const Test& other) {
        std::cout << "copy assign " << std::endl;
        if (this == &other) {
            return *this; 
        }
        return other;
    }

    Test(Test&&) {
        std::cout << "move ctor" << std::endl;
    }

    ~Test() { std::cout << "dtor\n";}

};

Test create() {
    return Test();
}

int main() {
    // copy will be elided unless you use the -fno-elide-constructors and -std=c++14
    // this is RVO in action
    auto a = create();
}