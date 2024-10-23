#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad arguments." << std::endl;
        return (1);
    }
    RPN rpn(av[1]);
    rpn.run();
    return (0);
}