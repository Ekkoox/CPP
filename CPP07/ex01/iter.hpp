#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void    iter(T* array, const size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

template <typename T>
void    increment(T& element)
{
    ++element;
}

template <typename T>
void    print(T& element)
{
    std::cout << element << std::endl;
}

#endif