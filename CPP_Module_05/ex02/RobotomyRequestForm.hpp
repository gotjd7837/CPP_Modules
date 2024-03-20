#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        std::string   target;
        RobotomyRequestForm();
    
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator = (const RobotomyRequestForm &copy);

        void execute(const Bureaucrat &executor) const;

        class RobotomyFailureException : public std::exception
        {
            public :
                const char* what() const throw();
        };
};

#endif