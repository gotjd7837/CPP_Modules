#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

AForm::AForm() : gradeToSign(1), gradeToExecute(1)
{

}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & copy) : name(copy.name), sign(copy.sign), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{

}

AForm::~AForm()
{

}

AForm& AForm::operator = (const AForm &copy)
{
    if (this == &copy)
        return *this;
    return *this;
}

void AForm::beSigned(const Bureaucrat &bur)
{
    if (bur.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->sign = true;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSign() const
{
    return this->sign;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

std::ostream& operator << (std::ostream& out, const AForm& form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSign())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute" << std::endl;
    return out;
}