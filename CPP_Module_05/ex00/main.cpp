#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Bureaucrat", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bureaucrat", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bureaucrat", 150);
        b.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bureaucrat", 1);
        b.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat b("test", 1);
    std::cout << b << std::endl;

    return 0;
}