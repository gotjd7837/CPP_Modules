#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int val)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == val)
            return it;
    }
    throw std::runtime_error("Value not found");
}

#endif