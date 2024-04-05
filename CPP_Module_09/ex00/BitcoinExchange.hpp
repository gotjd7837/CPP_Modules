#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
    private :
        std::map<std::string, double> _data;
        int _checkDate(std::string key);
        int _checkValue(double value);

    public :
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        
        void run(char* filename);
};

#endif