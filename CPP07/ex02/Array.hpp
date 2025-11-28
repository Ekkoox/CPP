#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
    private:
        T* _array;
        std::size_t _size;

    public:
        Array() : _array(new T[0]), _size(0) {}

        Array(std::size_t n) : _array(new T[n]()), _size(n) {}

        Array(const Array& other) : _array(new T[other._size]), _size(other._size)
        {
            for (std::size_t i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;
                _size = other._size;
                _array = new T[_size];
                for (std::size_t i = 0; i < _size; ++i)
                    _array[i] = other._array[i];
            }
            return *this;
        }

        ~Array()
        {
            delete[] _array;
        }

        T& operator[](std::size_t index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        const T& operator[](std::size_t index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        std::size_t size() const
        {
            return _size;
        }
};

#endif