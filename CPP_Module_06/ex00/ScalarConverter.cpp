#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &input)
{
    e_type type = getType(input);

    switch (type)
    {
        case CHAR :
            convertChar(input);
            break;
        case INT :
            convertInt(input);
            break;
        case FLOAT :
            convertFloat(input);
            break;
        case DOUBLE :
            convertDouble(input);
            break;
        case NANUMBER :
            convertNan();
            break;
        case P_INF :
            convertPInf();
            break;
        case N_INF :
            convertNInf();
            break;
    }
}

const char* ScalarConverter::nonDisplayable::what() const throw()
{
    return ("Non displayable");
}

const char* ScalarConverter::invalidInput::what() const throw()
{
    return ("Invalid input");
}