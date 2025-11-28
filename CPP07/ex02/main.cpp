/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:45:03 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/28 16:42:17 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    std::cout << "=== Test with int ===" << std::endl;
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        intArray[i] = static_cast<int>(i + 1);
    }
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        std::cout << intArray[i] << std::endl;
    }

    std::cout << "=== Test with const int ===" << std::endl;
    const Array<int> constIntArray = intArray;
    for (size_t i = 0; i < constIntArray.size(); ++i)
    {
        std::cout << constIntArray[i] << std::endl;
    }

    std::cout << "\n=== Test out of range exception ===" << std::endl;
    try
    {
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test with string ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "hello";
    strArray[1] = "world";
    strArray[2] = "CPP";
    for (size_t i = 0; i < strArray.size(); ++i)
    {
        std::cout << strArray[i] << std::endl;
    }

    return (0);
}