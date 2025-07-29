/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:24:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/07/29 15:38:31 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(const std::string &name) {
    firstname = name;
}

void Contact::setLastName(const std::string &name) {
    lastname = name;
}

void Contact::setNickname(const std::string &name) {
    nickname = name;
}

void Contact::setPhoneNumber(const std::string &number) {
    phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string &secret) {
    darkestsecret = secret;
}
