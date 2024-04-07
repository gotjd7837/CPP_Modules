#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        _data = copy._data;
    return (*this);
}

void BitcoinExchange::_printInfo(std::string key, double value)
{
    std::map<std::string, double>::iterator it = _data.find(key);

    if (it == _data.end())
    {
        std::cout << "Error: date not found" << std::endl;
        return ;
    }
    std::cout << key << " | " << value << " | " << it->second << std::endl;
}

int BitcoinExchange::_checkValue(double value)
{
    // if (value <= 0)
    // {
    //     std::cout << "Error: bad value" << std::endl;
    //     return (0);
    // }
    // return (1);
}

int BitcoinExchange::_checkDate(std::string key)
{
    std::stringstream ss(key);
    std::string s;
    int year, month, day;
    int i = 0;

    while (std::getline(ss, s, '-'))
    {
        if (i == 0)
        {
            year = std::atoi(s.c_str());
            if (year < 2009 || year > 2023) {
                std::cout << "Error: bad Date" << std::endl;
                return (0);
            }
        }
        else if (i == 1)
        {
            month = std::atoi(s.c_str());
            if (month < 1 || month > 12) {
                std::cout << "Error: bad Date" << std::endl;
                return (0);
            }
        }
        else if (i == 2)
        {
            day = std::atoi(s.c_str());
            if (day < 1 || day > 31) {
                std::cout << "Error: bad Date" << std::endl;
                return (0);
            }
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
                std::cout << "Error: bad Date" << std::endl;
                return (0);
            }
            if (month == 2)
            {
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                {
                    if (day > 29) {
                        std::cout << "Error: bad Date" << std::endl;
                        return (0);
                    }
                }
                else if (day > 28) {
                    std::cout << "Error: bad Date" << std::endl;
                    return (0);
                }
            }
        }
        i++;
    }
    if (i != 3)
    {
        std::cout << "Error: bad Date" << std::endl;
        return (0);
    }
    return (1);
}

void BitcoinExchange::_parseData()
{
    std::ifstream   csv("data.csv");
    std::string     line;
    std::string     key;
    double          value;

    if (!csv.is_open())
        throw std::runtime_error("Error: could not open file.");
    while (std::getline(csv, line))
    {
        if (line == "date,exchange_rate")
            continue ;

        std::stringstream ss(line);
        std::getline(ss, key, ',');
        ss >> value;
        _data.insert(std::pair<std::string, double>(key, value));
    }
}

void BitcoinExchange::_processInfile(char* filename)
{
    std::ifstream   infile(filename);
    std::string     line;
    std::string     key;
    char            pipe;
    double          value;

    if (!infile.is_open())
        throw std::runtime_error("Error: could not open file.");

    while (std::getline(infile, line))
    {
        if (line == "" || line == "date | value")
            continue ;

        pipe = 0;
        std::stringstream ss(line);

        if (!(ss >> key))
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }
        if (!_checkDate(key))
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
        if (!_checkValue(value))
            continue ;

        _printInfo(key, value);
    }
}

void BitcoinExchange::run(char* filename)
{
    try
    {
        _parseData();
        _processInfile(filename);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}