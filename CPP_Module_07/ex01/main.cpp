#include "iter.hpp"

int main()
{
    int intarr[] = {1, 2, 3, 4, 5};
    float floatarr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char chararr[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "intarr: " << std::endl;
    iter(intarr, 5, print<int>);
    std::cout << "floatarr: " << std::endl;
    iter(floatarr, 5, print<float>);
    std::cout << "chararr: " << std::endl;
    iter(chararr, 5, print<char>);
    return 0;
}