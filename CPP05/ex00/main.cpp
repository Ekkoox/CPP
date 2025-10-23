/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:38:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/10/23 16:47:12 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat bureaucrat("John", 42);
    std::cout << bureaucrat << std::endl;

    bureaucrat.incrementGrade();
    std::cout << bureaucrat << std::endl;

    bureaucrat.decrementGrade();
    std::cout << bureaucrat << std::endl;

    return (0);
}