#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed { 

    private:
        int            _value;
        static const int    _fractionalBits = 8;

    public :
        Fixed();
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);

        Fixed &operator--();
        Fixed operator--(int);
        ~Fixed();
        int getRawBits(void) const;
        void SetRawBits(int const raw);

};

#endif