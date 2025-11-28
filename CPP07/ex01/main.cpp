/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:23:31 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/28 11:51:13 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    std::cout << "=== Test with int ===" << std::endl;
    int tab[] = {1, 2, 3, 4, 5};
    iter(tab, 5, print<int>);

    std::cout << "\n=== Increment ints ===" << std::endl;
    iter(tab, 5, increment<int>);
    iter(tab, 5, print<int>);

    std::cout << "\n=== Test with double ===" << std::endl;
    double dtab[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(dtab, 5, print<double>);

    std::cout << "\n=== Increment doubles ===" << std::endl;
    iter(dtab, 5, increment<double>);
    iter(dtab, 5, print<double>);

    std::cout << "\n=== Test with string ===" << std::endl;
    std::string strs[] = {"hello", "world", "CPP"};
    iter(strs, 3, print<std::string>);
    
    return (0);
}