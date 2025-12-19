/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:46:33 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/19 18:03:53 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVector(0), _timeDeque(0)
{
    return;
}

PmergeMe::~PmergeMe()
{
    return;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vector = other._vector;
        this->_deque = other._deque;
        this->_timeVector = other._timeVector;
        this->_timeDeque = other._timeDeque;
    }
    return (*this);
}

int PmergeMe::parseInput(int ac, char **av) {
    std::set<int> seen; // Pour détecter les doublons efficacement

    for (int i = 1; i < ac; ++i) { // On commence à 1 pour sauter le nom du programme
        std::string s(av[i]);
        
        // Vérification que la string ne contient que des chiffres
        if (s.empty() || s.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error: Invalid input '" << s << "'" << std::endl;
            return (EXIT_FAILURE);
        }

        // Conversion sécurisée
        try {
            long val = std::atol(s.c_str()); // ou std::stol(s)
            if (val > INT_MAX) 
                throw std::out_of_range("");
            
            int num = static_cast<int>(val);
            
            // Doublons
            if (!seen.insert(num).second) {
                std::cerr << "Error: Duplicate found: " << num << std::endl;
                return (EXIT_FAILURE);
            }
            std::cout << "Parsed number: " << num << std::endl;
            _vector.push_back(num);
            _deque.push_back(num);
        } catch (const std::out_of_range&) {
            std::cerr << "Error: Number out of range" << std::endl;
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

std::vector<size_t> generateJacobsthal(size_t n)
{
    std::vector<size_t> jacobsthal;
    size_t j0 = 0;
    size_t j1 = 1;
    jacobsthal.push_back(j0);
    if (n == 0) 
        return (jacobsthal);
    jacobsthal.push_back(j1);
    for (size_t i = 2; i < n; ++i) {
        size_t ji = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(ji);
    }
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        std::cout << jacobsthal[i] << " ";
    }
    std::cout << std::endl;
    return (jacobsthal);
}


void PmergeMe::sortVector()
{
    if (this->_vector.size() == 1)
    {
        std::cout << "Only one element, no sorting needed." << std::endl;
        return;
    }
    bool hasStraggler = (this->_vector.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = this->_vector.back();
        this->_vector.pop_back();
        std::cout << "Straggler is: " << straggler << std::endl;
    }
    
    std::vector<std::pair<int, int> > pairs;
    
    std::cout << "Raw pairs from input: ";
    for (size_t i = 0; i < this->_vector.size(); i += 2) 
    {
        int a = _vector[i];
        int b = _vector[i + 1];

        std::cout << "[" << a << ", " << b << "] ";

        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    std::cout << std::endl;
    
    std::cout << "Pairs before Ford-Johnson: ";
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "] ";
    }
    std::cout << std::endl;
    
    //Ford-Johnson part to be implemented

    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> temp = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].second > temp.second) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = temp;
    }

    std::cout << "Pairs after Ford-Johnson: ";
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "] ";
    }
    std::cout << std::endl;

    // Jacobsthal sequence generation

    generateJacobsthal(pairs.size());
    
    std::cout << "Jacobsthal sequence up to " << pairs.size() << std::endl;

}
