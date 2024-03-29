#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
    private :
        T* arr;
        unsigned int size;

    public :
        Array() : arr(new T[0]), size(0) {}
        Array(unsigned int n) : arr(new T[n]), size(n) {}
        
        Array(const Array& copy) : arr(new T[copy.size]), size(copy.size)
        {
            for (unsigned int i = 0; i < size; i++)
                this->arr[i] = copy.arr[i];
        }
        ~Array()
        {
            delete[] this->arr;
        }
        Array& operator = (const Array& copy)
        {
            if (this == &copy)
                return *this;

            delete[] this->arr;
            this->arr = new T[copy.size];
            this->size = copy.size;
            for (unsigned int i = 0; i < this->size; i++)
                this->arr[i] = copy.arr[i];

            return *this;
        }

        T& operator [] (unsigned int i)
        {
            if (i >= this->size)
                throw std::out_of_range("Index out of range");
            return this->arr[i];
        }

        const T& operator [] (unsigned int i) const
        {
            if (i >= this->size)
                throw std::out_of_range("Index out of range");
            return this->arr[i];
        }

        unsigned int Size() const
        {
            return this->size;
        }
};

#endif