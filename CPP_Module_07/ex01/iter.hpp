#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T* arr, int size, Func func)
{
    for (int i = 0; i < size; i++)
        func(arr[i]);
}

template <typename T>
void print(const T& x)
{
    std::cout << x << std::endl;
}

#endif