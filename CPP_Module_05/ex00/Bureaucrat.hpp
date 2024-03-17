#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private :
        const std::string   name;
        int                 grade;

    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &op);

        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();

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

#endif