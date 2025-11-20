/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:01:01 by enschnei          #+#    #+#             */
/*   Updated: 2025/11/20 19:06:22 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"

int main()
{
    Data data("Test Data");
    Serialization *Key = NULL;

    uintptr_t raw;
    std::cout << "Original value: " << &data << std::endl;
    raw = Key->serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Raw adress: " << &raw << std::endl;
    std::cout << "Deserialized value: " << Key->deserialize(raw) << std::endl;
    return 0;
}
