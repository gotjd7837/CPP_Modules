#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

const char* RobotomyRequestForm::RobotomyFailureException::what() const throw()
{
    return "Robotomy failed";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &copy)
{
    if (this == &copy)
        return *this;
    AForm::operator = (copy);
    this->target = copy.target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSign())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (rand() % 2)
        std::cout << "RRRRRRRRRRRR~" << std::endl;
    else
        throw RobotomyRequestForm::RobotomyFailureException();
}
