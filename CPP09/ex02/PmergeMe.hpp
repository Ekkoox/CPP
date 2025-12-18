#ifndef PERGE_ME_HPP
#define PERGE_ME_HPP

#include <iostream>
#include <stdlib.h>
#include <climits>
#include <set>
#include <ctime>
#include <vector>
#include <deque>

class PmergeMe
{
    private :
        std::vector<int> _vector;
        std::deque<int> _deque;
        double _timeVector;
        double _timeDeque;

    public :
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        int parseInput(int ac, char **av);
        void sortVector();
        void sortDeque();
        // void printResults() const;
};

#endif