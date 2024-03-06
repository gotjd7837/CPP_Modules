/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:02 by haekang           #+#    #+#             */
/*   Updated: 2024/03/06 13:36:20 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contactCount = 0;
}

void		PhoneBook::add()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    static int  index;

    if (index == 8)
        index = 0;
    if (!this->inputFirstName(firstName))
        return ;
    if (!this->inputLastName(lastName))
        return ;
    if (!this->inputNickname(nickname))
        return ;
    if (!this->inputPhoneNumber(phoneNumber))
        return ;
    if (!this->inputDarkestSecret(darkestSecret))
        return ;
    this->contacts[index] = Contact(
        firstName,
        lastName,
        nickname,
        phoneNumber,
        darkestSecret
    );
    index++;
    if (this->contactCount < 8)
        this->contactCount++;
}

void		PhoneBook::search()
{
    int			i;
    int			index;

    i = 0;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    while (i < this->contactCount)
    {
        std::cout << "         " << i << "|";
        std::cout << truncated(this->contacts[i].getFirstName()) << "|";
        std::cout << truncated(this->contacts[i].getLastName()) << "|";
        std::cout << truncated(this->contacts[i].getNickname()) << std::endl;
        i++;
    }
    std::cout << "Enter index: ";
    if (!this->inputIndex(index))
        return ;
    if (index >= 0 && index < this->contactCount)
    {
        std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
        std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
}
