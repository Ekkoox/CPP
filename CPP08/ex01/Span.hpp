#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

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
};

#endif