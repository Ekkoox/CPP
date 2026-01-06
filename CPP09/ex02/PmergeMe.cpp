/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:46:33 by enschnei          #+#    #+#             */
/*   Updated: 2026/01/06 17:49:48 by enschnei         ###   ########.fr       */
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
            _vector.push_back(num);
            _deque.push_back(num);
        } catch (const std::out_of_range&) {
            std::cerr << "Error: Number out of range" << std::endl;
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

std::vector<size_t> generateJacobsthalIndices(size_t n)
{
    std::vector<size_t> indices;

    size_t j_prev = 0;
    size_t j_curr = 1;

    while (j_curr < n)
    {
        if (j_curr > 0)
            indices.push_back(j_curr);

        size_t next = j_curr + 2 * j_prev;
        j_prev = j_curr;
        j_curr = next;
    }
    return (indices);
}

void PmergeMe::sortVector()
{
    clock_t start = clock();
    
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

    // 1. Extraire la Main Chain (S) et le Pend (P)
    // S contiendra : pairs[0].second, pairs[1].second...
    // P contiendra : pairs[0].first, pairs[1].first...
    
    std::vector<int> S;
    std::vector<int> P;

    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        S.push_back(pairs[i].second);
        P.push_back(pairs[i].first);
    }
    
    // 2. Insérer P[0] au début de S (gratuit)
    
    S.insert(S.begin(), P[0]);
    
    // 3. Utiliser les nombres de Jacobsthal pour déterminer l'ordre d'insertion de P[i]

    std::vector<size_t> order = generateJacobsthalIndices(P.size());
    
    // 4. Pour chaque élément choisi, utiliser std::lower_bound pour l'insérer dans S
    
    std::vector<bool> inserted(P.size(), false);
    inserted[0] = true;

    for (size_t i = 0; i < order.size(); ++i) 
    {
        size_t idx = order[i];
        if (idx < P.size())
        {
            int elementToInsert = P[idx];
            // Insérer elementToInsert dans S à la position correcte
            std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), elementToInsert);
            S.insert(pos, elementToInsert);
            inserted[idx] = true;
        }
    }
    
    for (size_t i = 1; i < P.size(); ++i)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), P[i]);
            S.insert(pos, P[i]);
        }
    }

    // 5. Si straggler, l'insérer dans S à la fin
    
    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(pos, straggler);
    }
    
    this->_vector = S;
    
    // 6. Enregistrer le temps de fin
    clock_t end = clock();
    _timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // en microsecondes
}

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    
    if (this->_deque.size() == 1)
    {
        std::cout << "Only one element, no sorting needed." << std::endl;
        return;
    }
    bool hasStraggler = (this->_deque.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = this->_deque.back();
        this->_deque.pop_back();
    }
    
    std::deque<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i < this->_deque.size(); i += 2) 
    {
        int a = _deque[i];
        int b = _deque[i + 1];

        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    // Ford-Johnson sorting
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> temp = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].second > temp.second) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = temp;
    }

    std::deque<int> S;
    std::deque<int> P;

    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        S.push_back(pairs[i].second);
        P.push_back(pairs[i].first);
    }
    
    S.insert(S.begin(), P[0]);
    
    std::vector<size_t> order = generateJacobsthalIndices(P.size());
    
    std::vector<bool> inserted(P.size(), false);
    inserted[0] = true;

    for (size_t i = 0; i < order.size(); ++i) 
    {
        size_t idx = order[i];
        if (idx < P.size())
        {
            int elementToInsert = P[idx];
            std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), elementToInsert);
            S.insert(pos, elementToInsert);
            inserted[idx] = true;
        }
    }
    
    for (size_t i = 1; i < P.size(); ++i)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), P[i]);
            S.insert(pos, P[i]);
        }
    }
    
    if (hasStraggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(pos, straggler);
    }
    
    this->_deque = S;
    
    clock_t end = clock();
    _timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // en microsecondes
}

void PmergeMe::printResults() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << _timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque : " << _timeDeque << " us" << std::endl;
}
