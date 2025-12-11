#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>

void evaluate_rpn(const std::string &expression);
long long operator_check(char op, long long a, long long b);

#endif