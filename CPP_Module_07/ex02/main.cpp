#include "Array.hpp"

int main()
{
    std::cout << "-------test1--------" << std::endl;
    {

    }









    Array<int> intarr(5);
    Array<float> floatarr(5);
    Array<char> chararr(5);

    for (unsigned int i = 0; i < 5; i++)
    {
        intarr[i] = i + 1;
        floatarr[i] = (i + 1) * 1.1;
        chararr[i] = 'a' + i;
    }

    std::cout << "intarr: " << std::endl;
    for (unsigned int i = 0; i < 5; i++)
        std::cout << intarr[i] << std::endl;
    std::cout << "floatarr: " << std::endl;
    for (unsigned int i = 0; i < 5; i++)
        std::cout << floatarr[i] << std::endl;
    std::cout << "chararr: " << std::endl;
    for (unsigned int i = 0; i < 5; i++)
        std::cout << chararr[i] << std::endl;










    std::cout << "intarr[5]: " << std::endl;
    try
    {
        std::cout << "size: " << intarr.Size() << std::endl;
        intarr[5] = 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}