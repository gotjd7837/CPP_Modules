#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
        MutantStack &operator=(const MutantStack &copy) { std::stack<T>::operator=(copy); return *this; }
        ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
        reverse_iterator rend() { return std::stack<T>::c.rend(); }
};

#endif