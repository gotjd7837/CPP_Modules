#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string   target;
        ShrubberyCreationForm();
    
    public :
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator = (const ShrubberyCreationForm &copy);

        void execute(const Bureaucrat &executor) const;
};

#endif