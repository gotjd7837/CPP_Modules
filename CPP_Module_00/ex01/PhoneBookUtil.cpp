/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtil.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:08:00 by haekang           #+#    #+#             */
/*   Updated: 2024/02/05 13:32:59 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string truncated(std::string str)
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

int inputFirstName(std::string &firstName)
{
    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, firstName))
        return (0);
    if (std::cin.eof())
        return (0);
    if (firstName == "")
    {
        std::cout << "First name cannot be empty" << std::endl;
        return (0);
    }
    return (1);
}

int inputLastName(std::string &lastName)
{
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, lastName))
        return (0);
    if (std::cin.eof())
        return (0);
    if (lastName == "")
    {
        std::cout << "Last name cannot be empty" << std::endl;
        return (0);   
    }
    return (1);
}

int inputNickname(std::string &nickname)
{
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickname))
        return (0);
    if (std::cin.eof())
        return (0);
    if (nickname == "")
    {
        std::cout << "Nickname cannot be empty" << std::endl;
        return (0);   
    }
    return (1);
}

int inputPhoneNumber(std::string &phoneNumber)
{
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phoneNumber))
        return (0);
    if (std::cin.eof())
        return (0);
    if (phoneNumber == "")
    {
        std::cout << "Phone number cannot be empty" << std::endl;
        return (0);   
    }
    return (1);
}

int inputDarkestSecret(std::string &darkestSecret)
{
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return (0);
    if (std::cin.eof())
        return (0);
    if (darkestSecret == "")
    {
        std::cout << "Darkest secret cannot be empty" << std::endl;
        return (0);   
    }
    return (1);
}

int inputIndex(int &index)
{
    std::string input;

    if (!std::getline(std::cin, input))
        return (0);
    if (std::cin.eof())
        return (0);
    if (input == "")
    {
        std::cout << "Index cannot be empty" << std::endl;
        return (0);
    }
    if (input.length() > 1)
    {
        std::cout << "Invalid index" << std::endl;
        return (0);
    }
    if (input[0] < '0' || input[0] > '7')
    {
        std::cout << "Invalid index" << std::endl;
        return (0);
    }
    index = input[0] - '0';
    return (1);
}