#include "whatever.hpp"

int main()
{
    std::cout << "--------test1---------" << std::endl;
    {
        int a = 2;
        int b = 3;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap_(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << min_(a, b) << std::endl;
        std::cout << "max(a, b) = " << max_(a, b) << std::endl;
    }

    std::cout << "--------test2---------" << std::endl;
    {
        std::string a = "chaine1";
        std::string b = "chaine2";

        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap_(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << min_(a, b) << std::endl;
        std::cout << "max(a, b) = " << max_(a, b) << std::endl;
    }
}