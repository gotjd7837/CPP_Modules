#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::cout << *easyfind(vec, 3) << std::endl;
        std::cout << *easyfind(vec, 5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}