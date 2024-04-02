#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
    private :
        std::vector<int> vec_;
        unsigned int n_;
        Span();

    public :
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
};

#endif