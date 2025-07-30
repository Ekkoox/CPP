#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    private :
    std::string type;
    
    public :
    Weapon();
    void getType(void);
    void setType(void);
};

void getType(void);
void setType(void);

#endif 