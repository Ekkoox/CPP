/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:17:19 by enschnei          #+#    #+#             */
/*   Updated: 2025/12/11 19:32:21 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

long long operator_check(char op, long long a, long long b)
{
    if (op == '+')
        return (a + b);
    else if (op == '-')
        return (a - b);
    else if (op == '*')
        return (a * b);
    else if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error: Division by zero");
        return (a / b);
    }
    else
        throw std::runtime_error("Error: Unknown operator");
}

void evaluate_rpn(const std::string &expression)
{
    std::stack<long long> stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            long long number = token[0] - '0';
            stack.push(number);
        }

        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            char op = token[0];

            if (stack.size() < 2)
                throw std::runtime_error("Error: Insufficient values in expression");
            long long b = stack.top();
            stack.pop();
            long long a = stack.top();
            stack.pop();
            long long result = operator_check(op, a, b);
            stack.push(result);
        }
        else 
        {
            throw std::runtime_error("Error: Invalid token in expression");
        }
    }
    if (stack.size() == 1)
        std::cout << "Result: " << stack.top() << std::endl;
    else if (stack.empty())
        throw std::runtime_error("Error: No values in the stack after evaluation");
    else 
        throw std::runtime_error("Error: Invalid expression");
}
