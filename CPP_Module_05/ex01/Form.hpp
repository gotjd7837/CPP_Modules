#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private :
        const std::string   name;
        bool                sign;
        const int           gradeToSign;
        const int           gradeToExecute;
        Form();
    
    public :
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &copy);
        ~Form();
        Form& operator = (const Form &copy);

        void        beSigned(const Bureaucrat &bur);

        std::string getName() const;
        bool        getSign() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public :
                const char* what() const throw();
        };
};

std::ostream& operator << (std::ostream& out, const Form& form);

#endif