/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:40 by haekang           #+#    #+#             */
/*   Updated: 2024/02/15 18:52:30 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private :
        int value;
        const static int bits = 8;
    public :
        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed& operator = (const Fixed& fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif