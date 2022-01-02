#include <iostream>

template<typename R, typename T, typename U>
R add(T x, U y) {
    return x+y;
}

template<typename T, typename U>
auto add2(T x, U y) -> decltype(x+y) {
    return x+y;
}

template<typename T, typename U>
auto add3(T x, U y){
    return x + y;
}

int main() {
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    if (std::is_same<decltype(x), int>::value)
        std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
        std::cout << "type x == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type z == type x" << std::endl;
    
    std::cout << "x+y = " << add2<int, int>(1,2) << std::endl;
    return 0;
}
