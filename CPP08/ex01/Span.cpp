/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:01:15 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/05 15:09:23 by enschnei         ###   ########.fr       */
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
