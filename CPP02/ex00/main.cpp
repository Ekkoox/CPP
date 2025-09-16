/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:27:33 by enschnei          #+#    #+#             */
/*   Updated: 2025/09/16 18:27:06 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
    
	c = b;
    
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// std::cout << (--a).getRawBits() << std::endl;
	// std::cout << a--.getRawBits() << std::endl;
	// std::cout << a.getRawBits() << std::endl;
    
	return (0);
}