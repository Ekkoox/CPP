#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"
#include <typeinfo>  
#include <iostream>
#include <cstdlib>
#include <ctime>

Base*   generate(void);
Base*   generateD(void);
void    identify(Base* p);
void    identify(Base& p);

#endif