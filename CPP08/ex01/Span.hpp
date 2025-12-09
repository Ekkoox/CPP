#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <limits>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int maxSize;

    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename InputIt>
        void addMultiple(InputIt begin, InputIt end);

        class SpanFullException : public std::exception {
            public:
                const char* what() const noexcept override {
                    return "Span is already full";
                }
        };

        class NotEnoughNumbersException : public std::exception {
            public:
                const char* what() const noexcept override {
                    return "Not enough numbers to find a span";
                }
        };
};

#endif