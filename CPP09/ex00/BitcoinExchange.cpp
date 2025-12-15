/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:06:45 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/15 17:20:38 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    return ;
}

BitcoinExchange::~BitcoinExchange() {
    return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->data = other.data;
    return ;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->data = other.data;
    }
    return (*this);
}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    std::string line;
    if (!std::getline(file, line)) {
        throw std::runtime_error("File is empty: " + filename);
    }
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        std::istringstream ss(line);
        std::string date;
        double rate;

        if (std::getline(ss, date, ',') && ss >> rate) {
            data[date] = rate;
        }
    }
    file.close();
}

int BitcoinExchange::isValideDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return 0;
    }
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); ++i) {
        if (!isdigit(yearStr[i])) return 0;
    }
    for (size_t i = 0; i < monthStr.length(); ++i) {
        if (!isdigit(monthStr[i])) return 0;
    }
    for (size_t i = 0; i < dayStr.length(); ++i) {
        if (!isdigit(dayStr[i])) return 0;
    }

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return (0);
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return (0);
    }
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28)) {
            return (0);
        }
    }
    return (1);
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = data.lower_bound(date);
    if (it != data.end() && it->first == date) {
        return (it->second);
    }
    if (it == data.begin()) {
        return (it->second);
    }
    --it;
    return (it->second);
}

void BitcoinExchange::processInput(const std::string& inputfile)
{
    std::ifstream file (inputfile.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open input file: " + inputfile);
    }
    std::string line;
    if (!std::getline(file, line))
    {
        throw std::runtime_error("Input file is empty: " + inputfile);
    }
    
    while(std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos - 1);
        std::string valueStr = line.substr(pipePos + 2);
        
        if (!isValideDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl; // Le sujet attend "bad input"
            continue;
        }
        
        char *endPtr;
        double value = std::strtod(valueStr.c_str(), &endPtr);
        if (valueStr.empty() || *endPtr != '\0') {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive numbe   r." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        double rate = getExchangeRate(date);
        if (rate < 0) {
            std::cerr << "Error: no exchange rate available for date => " << date << std::endl;
            continue;
        }
        double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
