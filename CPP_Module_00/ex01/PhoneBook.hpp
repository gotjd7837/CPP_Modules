/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:14 by haekang           #+#    #+#             */
/*   Updated: 2024/01/22 21:02:20 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
  private:
    int			contactCount;
    Contact		contacts[8];
  public:
    std::string	truncated(std::string str);
    void		add();
    void		search();
    PhoneBook();
};

#endif