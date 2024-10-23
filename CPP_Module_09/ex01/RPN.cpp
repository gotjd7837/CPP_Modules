#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(char *av) : _argvStr(av) { }

RPN::RPN(const RPN &other) { *this = other; }

RPN::~RPN() { }

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _argvStr = other._argvStr;
        _rpn = other._rpn;
    }
    return (*this);
}

void RPN::checkValue(std::string token)
{
    if (token.length() > 1)
        throw std::runtime_error("bad input.");
    for (size_t i = 0; i < token.length(); i++)
    {
        if (std::isdigit(token[i]) == false && token[i] != '.' && token[i] != '-' && token[i] != '+')
            throw std::runtime_error("bad input.");
    }
}

void RPN::calculate()
{
    std::stringstream ss(this->_argvStr);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        if (token == "")
            continue ;
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (this->_rpn.size() < 2)
            {
                std::cout << "Error: not enough operands." << std::endl;
                return ;
            }
            double a = this->_rpn.top();
            this->_rpn.pop();
            double b = this->_rpn.top();
            this->_rpn.pop();
            if (token == "+")
            {
                this->_rpn.push(b + a);
            }
            else if (token == "-")
            {
                this->_rpn.push(b - a);
            }
            else if (token == "*")
            {
                this->_rpn.push(b * a);
            }
            else if (token == "/")
            {
                this->_rpn.push(b / a);
            }
        }
        else
        {
            checkValue(token);
            double value = std::strtod(token.c_str(), NULL);
            this->_rpn.push(value);
        }
    }
    if (this->_rpn.size() != 1)
    {
        throw std::runtime_error("not enough operators.");
        return ;
    }
    return ;
}

void RPN::run()
{
    try {
        calculate();
        std::cout << this->_rpn.top() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}