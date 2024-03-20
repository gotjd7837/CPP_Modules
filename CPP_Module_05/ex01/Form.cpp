#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

Form::Form() : gradeToSign(1), gradeToExecute(1)
{

}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), sign(copy.sign), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{

}

Form::~Form()
{

}

Form& Form::operator = (const Form &copy)
{
    if (this == &copy)
        return *this;
    return *this;
}

void Form::beSigned(const Bureaucrat &bur)
{
    if (bur.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->sign = true;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSign() const
{
    return this->sign;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

std::ostream& operator << (std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSign())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute" << std::endl;
    return out;
}