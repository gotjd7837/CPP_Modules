#include "ScalarConverter.hpp"

e_type getType(const std::string &input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] < 32 || input[i] > 126)
            throw ScalarConverter::nonDisplayable();
    }
    if (input.length() == 1 && !isdigit(input[0]))
        return (CHAR);
    if (input == "nan")
        return (NANUMBER);
    if (input == "+inf")
        return (P_INF);
    if (input == "-inf")
        return (N_INF);
    if (input.find('.') != std::string::npos)
    {
        if (input.find('f') != std::string::npos)
            return (FLOAT);
        return (DOUBLE);
    }
    if (input.find('f') != std::string::npos)
        throw ScalarConverter::invalidInput();
    if (input.find('.') == std::string::npos)
        return (INT);
    throw ScalarConverter::invalidInput();
}

void convertChar(const std::string &input)
{
    std::cout << "char: '" << input[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

void convertInt(const std::string &input)
{
    int i = std::stoi(input);

    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void convertFloat(const std::string &input)
{
    float f = std::stof(input);

    if (f >= 32 && f <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertDouble(const std::string &input)
{
    double d = std::stod(input);

    if (d >= 32 && d <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void convertNan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void convertPInf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
}

void convertNInf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}
