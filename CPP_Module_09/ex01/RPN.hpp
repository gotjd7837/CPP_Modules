#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
    private :
        std::string _argvStr;
        std::stack<double> _rpn;

    RPN();

    void calculate();
    void checkValue(std::string token);

    public :
        RPN(char *av);
        RPN(const RPN &other);
        ~RPN();
        RPN &operator=(const RPN &other);

        void run();
};

#endif