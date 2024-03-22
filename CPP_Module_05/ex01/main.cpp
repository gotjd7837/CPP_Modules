#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bur("bur", 1);
        Form form("form", 1, 1);
        bur.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bur("bur", 150);
        Form form("form", 150, 150);
        bur.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bur("bur", 150);
        Form form("form", 149, 149);
        bur.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bur("bur", 1);
        Form form("form", 151, 2);
        bur.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bur("bur", 1);
        Form form("form", 0, 2);
        bur.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}