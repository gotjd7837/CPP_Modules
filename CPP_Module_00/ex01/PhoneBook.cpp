/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:34:02 by haekang           #+#    #+#             */
/*   Updated: 2024/01/30 07:47:28 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contactCount = 0;
}

std::string PhoneBook::truncated(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str.append(".");
    }
    else
    {
        while (str.length() < 10)
        {
            str.insert(0, " ");
        }
    }
    return (str);
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
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
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
        std::cout << this->truncated(this->contacts[i].getFirstName()) << "|";
        std::cout << this->truncated(this->contacts[i].getLastName()) << "|";
        std::cout << this->truncated(this->contacts[i].getNickname()) << std::endl;
        i++;
    }
    std::cout << "Enter index: ";
    std::cin >> index;
    if (std::cin.fail())
    {
        std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    if (std::cin.get() != '\n')
    {
        std::cout << "Please enter only one index" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    if (index >= 0 && index < this->contactCount)
    {
        std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
        std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
        std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }
}
