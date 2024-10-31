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
        
        void parseData();
        void processInfile(char* filename);
        int checkDate(std::string key);
        int checkValue(double value);
        void printInfo(std::string key, double value);

    public :
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        
        void run(char* filename);
};

#endif