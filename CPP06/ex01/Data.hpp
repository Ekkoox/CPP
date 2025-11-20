#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data
{
    private :
        std::string _name;
    
    public :
        Data(std::string name);
        Data(const Data &src);
        ~Data();
        Data &operator=(const Data &rhs);
        Data getName() const;
};

#endif