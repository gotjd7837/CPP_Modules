/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:14 by haekang           #+#    #+#             */
/*   Updated: 2024/03/06 13:30:26 by haekang          ###   ########.fr       */
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
    void		add();
    void		search();
    PhoneBook();

    std::string	truncated(std::string str);
    int	inputFirstName(std::string &firstName);
    int	inputLastName(std::string &lastName);
    int	inputNickname(std::string &nickname);
    int	inputPhoneNumber(std::string &phoneNumber);
    int inputDarkestSecret(std::string &darkestSecret);
    int inputIndex(int &index);
};
#endif