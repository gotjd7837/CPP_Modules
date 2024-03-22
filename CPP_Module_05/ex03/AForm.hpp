#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private :
        const std::string   name;
        bool                sign;
        const int           gradeToSign;
        const int           gradeToExecute;
        AForm();
    
    public :
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        virtual ~AForm();
        AForm& operator = (const AForm &copy);

        void        beSigned(const Bureaucrat &bur);
        virtual void execute(const Bureaucrat &executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            public :
                const char* what() const throw();
        };
};

std::ostream& operator << (std::ostream& out, const AForm& form);

#endif