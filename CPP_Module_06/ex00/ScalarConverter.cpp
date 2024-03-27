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
    try
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
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
}

const char* ScalarConverter::invalidInput::what() const throw()
{
    return ("Invalid input");
}

const char* ScalarConverter::impossibleConversion::what() const throw()
{
    return ("Impossible conversion");
}