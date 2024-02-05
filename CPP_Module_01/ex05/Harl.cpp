/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:33:34 by haekang           #+#    #+#             */
/*   Updated: 2024/02/05 20:55:04 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout
    << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
    << std::endl;
}

void Harl::info()
{
    std::cout
    << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
    << std::endl;
}

void Harl::warning()
{
    std::cout
    << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
    << std::endl;
}

void Harl::error()
{
    std::cout
    << "This is unacceptable! I want to speak to the manager now."
    << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
//멤버 함수를 함수 포인터로 사용해라!
}