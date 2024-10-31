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

void BitcoinExchange::printInfo(std::string key, double value)
{
    std::map<std::string, double>::iterator it = _data.find(key);

    if (it != _data.end())
        std::cout << key << " => " << value << " = " << it->second * value << std::endl;
    else
    {
        it = _data.upper_bound(key);
        if (it == _data.begin())
        {
            std::cout << "Error: date not found" << std::endl;
            return ;
        }
        it--;
        std::cout << key << " => " << value << " = " << it->second * value << std::endl;
    }
    return ;
}

int BitcoinExchange::checkValue(double value)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (0);
    }
    else if (value == 0)
    {
        std::cout << "Error: bad value" << std::endl;
        return (0);
    }
    else if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (0);
    }
    return (1);
}

int BitcoinExchange::checkDate(std::string key)
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
            if (year < 2009 || year > 2022) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
        }
        else if (i == 1)
        {
            month = std::atoi(s.c_str());
            if (month < 1 || month > 12) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
            if ((month >= 1 && month <= 9) && s.size() == 1) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
        }
        else if (i == 2)
        {
            day = std::atoi(s.c_str());
            if (day < 1 || day > 31) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
            if ((day >= 1 && day <= 9) && s.size() == 1) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                if (day > 29 && month == 2) {
                    std::cout << "Error: bad input => " << ss.str() << std::endl;
                    return (0);
                }
            } else if (day > 28 && month == 2) {
                std::cout << "Error: bad input => " << ss.str() << std::endl;
                return (0);
            }
        }
        i++;
    }
    if (i != 3)
    {
        std::cout << "Error: bad input => " << ss.str() << std::endl;
        return (0);
    }
    return (1);
}

void BitcoinExchange::parseData()
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

void BitcoinExchange::processInfile(char* filename)
{
    std::ifstream   infile(filename);
    std::string     line;
    std::string     key;
    double          value;

    if (!infile.is_open())
        throw std::runtime_error("Error: could not open file.");

    infile.seekg(0, std::ios::end);
    if (infile.tellg() == 0)
        throw std::runtime_error("Error: file is empty");
    infile.seekg(0, std::ios::beg);

    while (std::getline(infile, line))
    {
        if (line == "" || line == "date | value")
            continue ;

        char    pipe = 0;
        std::stringstream ss(line);

        if (!(ss >> key))
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }
        if (!checkDate(key))
            continue ;

        if (!(ss >> pipe) || pipe != '|')
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }

        if (!(ss >> value))
        {
            std::cout << "Error: bad input" << std::endl;
            continue ;
        }
        if (!checkValue(value))
            continue ;

        printInfo(key, value);
    }
}

void BitcoinExchange::run(char* filename)
{
    try
    {
        parseData();
        processInfile(filename);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}