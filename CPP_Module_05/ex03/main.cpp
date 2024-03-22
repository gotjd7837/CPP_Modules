#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "----------test1----------" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat b("Bureaucrat", 1);
        AForm *r = intern.makeForm("RobotomyRequestForm", "r");
        AForm *p = intern.makeForm("PresidentialPardonForm", "p");
        AForm *s = intern.makeForm("ShrubberyCreationForm", "s");

        b.signForm(*r);
        b.signForm(*p);
        std::cout << *r;
        std::cout << *p;
        std::cout << *s;

        b.executeForm(*r);
        b.executeForm(*p);
        b.executeForm(*s);

        delete r;
        delete p;
        delete s;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------test2----------" << std::endl;
    try
    {
        Intern intern;
        Bureaucrat b("Bureaucrat", 80);
        AForm *r = intern.makeForm("RobotomyRequestForm", "r");
        AForm *p = intern.makeForm("PresidentialPardonForm", "p");
        AForm *s = intern.makeForm("ShrubberyCreationForm", "s");

        b.signForm(*r);
        b.signForm(*p);
        b.signForm(*s);

        b.executeForm(*r);
        b.executeForm(*p);
        b.executeForm(*s);

        delete r;
        delete p;
        delete s;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------test3----------" << std::endl;
    try
    {
        Intern intern;
        AForm *r = intern.makeForm("RoquestForm", "r");
        // AForm *p = intern.makeForm("PrasdForm", "p");
        // AForm *s = intern.makeForm("zzzzeationForm", "s");

        delete r;
        // delete p;
        // delete s;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}