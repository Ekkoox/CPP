/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:01:15 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/08 17:11:51 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::~Span() {
    return ;
}

Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {
    return ;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->numbers = other.numbers;
        this->maxSize = other.maxSize;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::overflow_error("Span is already full");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return (minSpan);
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int minNumber = *std::min_element(numbers.begin(), numbers.end());
    int maxNumber = *std::max_element(numbers.begin(), numbers.end());
    return (maxNumber - minNumber);
}
