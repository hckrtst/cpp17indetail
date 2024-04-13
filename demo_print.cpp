/*
Shows some of the new features

*/

#include <iostream>
#include <string>

template<typename T> void linePrinter(const T& x) {
    if constexpr (std::is_integral_v<T>) { // evaluates at compile time
        std::cout << "num: " << x << std::endl;
    }
    else if constexpr (std::is_floating_point_v<T>) {
        const auto frac = x - static_cast<long>(x);
        std::cout << "flt: " << x << ", frac " << frac << std::endl;
    }
    else if constexpr (std::is_pointer_v<T>) {
        std::cout << "ptr, ";
        linePrinter(*x);
    }
    else {
        std::cout << x << '\n';
    }
}

template<typename ... Args> void printWithInfo(Args ... args) {
    (linePrinter(args), ...); // fold expr over comma operator
}

int main() {
    int i = 10;
    float f = 1.34578f;
    std::string name = "hilltop";
    printWithInfo("testing", i, &f, 123456, L"hello this is so cool", name);
}
