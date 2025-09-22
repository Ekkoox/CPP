#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed { 

    private:
        int                 _value;
        static const int    _fractionalBits = 8;

    public :
        Fixed();
        Fixed(const int intvalue);
        Fixed(const float floatvalue);
        Fixed(const Fixed &src);
        ~Fixed();
        Fixed &operator=(const Fixed &srx);
        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;
        Fixed &operator++(void); // Prefix increment
        Fixed operator++(int); // Postfix increment
        Fixed &operator--(void); // Prefix decrement
        Fixed operator--(int); // Postfix decrement
        bool operator>(const Fixed &rhs) const;
        bool operator<(const Fixed &rhs) const;
        bool operator>=(const Fixed &rhs) const;
        bool operator<=(const Fixed &rhs) const;
        bool operator==(const Fixed &rhs) const;
        bool operator!=(const Fixed &rhs) const;
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif