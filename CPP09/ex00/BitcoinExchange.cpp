/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:06:45 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/12 15:59:06 by enschnei         ###   ########.fr       */
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
        char delimiter;

        if (std::getline(ss, date, ',') && ss >> rate) {
            data[date] = rate;
        }
    }
    file.close();
}
