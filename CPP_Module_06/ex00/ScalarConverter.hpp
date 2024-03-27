#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <limits>
# include <cfloat>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NANUMBER,
    P_INF,
    N_INF
};

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

    public :
        static void convert(const std::string &input);

        class invalidInput : public std::exception
        {
            public :
                const char* what() const throw();
        };

        class impossibleConversion : public std::exception
        {
            public :
                const char* what() const throw();
        };
};

e_type getType(const std::string &input);
void convertChar(const std::string &input);
void convertInt(const std::string &input);
void convertFloat(const std::string &input);
void convertDouble(const std::string &input);
void convertNan();
void convertPInf();
void convertNInf();


#endif