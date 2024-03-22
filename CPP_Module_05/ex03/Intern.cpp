#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern& Intern::operator = (const Intern &copy)
{
    (void)copy;
    return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i]);
        }
        delete forms[i];
    }
    throw FormNotFoundException();
    
    return (NULL);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}