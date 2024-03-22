#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &copy)
{
    if (this == &copy)
        return *this;
    AForm::operator = (copy);
    this->target = copy.target;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSign())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
