#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange 
{
    private:
        std::map<std::string, double> data;
        
        public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void loadData(const std::string& filename);
        void processInput(const std::string& inputFile);
        int isValideDate(const std::string& date) const;
        double getExchangeRate(const std::string& date) const;
};

#endif