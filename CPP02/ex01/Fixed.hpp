#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif