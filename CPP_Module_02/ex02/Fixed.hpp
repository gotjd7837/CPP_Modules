/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:40 by haekang           #+#    #+#             */
/*   Updated: 2024/02/17 16:15:00 by haekang          ###   ########.fr       */
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
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& copy);
        Fixed& operator = (const Fixed& fixed);
        ~Fixed();
        
        static Fixed& min(Fixed& fixed1, Fixed& fixed2);
        const static Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
        
        static Fixed& max(Fixed& fixed1, Fixed& fixed2);
        const static Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        
        bool operator > (const Fixed& fixed) const;
        bool operator < (const Fixed& fixed) const;
        bool operator >= (const Fixed& fixed) const;
        bool operator <= (const Fixed& fixed) const;
        bool operator == (const Fixed& fixed) const;
        bool operator != (const Fixed& fixed) const;

        Fixed operator + (const Fixed& fixed) const;
        Fixed operator - (const Fixed& fixed) const;
        Fixed operator * (const Fixed& fixed) const;
        Fixed operator / (const Fixed& fixed) const;
        
        Fixed& operator ++ (void);
        const Fixed operator ++ (int);
        Fixed& operator -- (void);
        const Fixed operator -- (int);
};

std::ostream& operator << (std::ostream& out, const Fixed& fixed);

#endif