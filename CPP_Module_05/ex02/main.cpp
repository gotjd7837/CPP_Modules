#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "----------test1----------" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        RobotomyRequestForm r("r");
        PresidentialPardonForm p("p");
        ShrubberyCreationForm s("s");

        b.signForm(r);
        b.signForm(p);
        std::cout << r;
        std::cout << p;
        std::cout << s;

        b.executeForm(r);
        b.executeForm(p);
        b.executeForm(s);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------test2----------" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 80);
        RobotomyRequestForm r("r");
        PresidentialPardonForm p("p");
        ShrubberyCreationForm s("s");

        b.signForm(r);
        b.signForm(p);
        b.signForm(s);

        b.executeForm(r);
        b.executeForm(p);
        b.executeForm(s);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}