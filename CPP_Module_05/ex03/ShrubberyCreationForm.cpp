#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return *this;
    AForm::operator = (copy);
    this->target = copy.target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSign())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream outfile(this->target + "_shrubbery");
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << std::endl;
    outfile.close();
}