#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream   csv("data.csv");
    std::string     line;
    std::string     key;
    double          value;

    if (!csv.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    while (std::getline(csv, line))
    {
        if (line == "date,exchange_rate")
            continue ;

        std::stringstream ss(line);
        std::getline(ss, key, ',');
        if (!(ss >> value))
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }
        _data.insert(std::pair<std::string, double>(key, value));
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        _data = copy._data;
    return (*this);
}

void BitcoinExchange::run(char* filename)
{
    std::ifstream   infile(filename);
    std::string     line;
    std::string     key;
    char            pipe;
    double          value;

    if (!infile.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }
    while (std::getline(infile, line))
    {
        if (line == "")
            continue ;

        pipe = 0;
        std::stringstream ss(line);
        ss >> key;
        if (key == "date")
            continue ;
        if (!(ss >> pipe) && pipe != '|')
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }
        if (!(ss >> value))
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }

        _checkDate(key);
        _checkValue(value);
        // printInfo(key, value);
        트라이 캐치로 안되나 .. ?
    }
}

// int BitcoinExchange::_checkDate(std::string key)
// {
//     if (_data.find(key) == _data.end())
//     {
//         std::cout << "Error: date not found." << std::endl;
//         exit(1);
//     }
// }

int BitcoinExchange::_checkValue(double value)
{
    if (value < 0)
        std::cout << "Error: not a positive number." << std::endl;
    if (value > 1000)
        std::cout << "Error: too large a number." << std::endl;
}

// void BitcoinExchange::checkPair(std::string key, double value)
// {
//     // if (_data.find(key) != _data.end())
//     // {
//     //     std::cout << "Error: duplicate date" << std::endl;
//     //     exit(1);
//     // }
//     (void)key;
//     if (value < 0)
//     {
//         std::cout << "Error: not a positive number." << std::endl;
//     }
//     if (value > 1000)
//     {
//         std::cout << "Error: too large a number." << std::endl;
//     }
// }