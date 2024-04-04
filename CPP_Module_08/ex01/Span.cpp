#include "Span.hpp"

Span::Span(unsigned int n) : n_(n) {}

Span::Span(const Span &copy) : vec_(copy.vec_), n_(copy.n_) {}

Span &Span::operator=(const Span &copy)
{
    if (this == &copy)
        return (*this);
    vec_ = copy.vec_;
    n_ = copy.n_;
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (vec_.size() >= n_)
        throw std::runtime_error("Span is full");
    vec_.push_back(n);
}

int Span::shortestSpan()
{
    if (vec_.size() <= 1)
        throw std::runtime_error("Span is too short");
    std::sort(vec_.begin(), vec_.end());
    int min = vec_[1] - vec_[0];
    for (size_t i = 2; i < vec_.size(); i++)
    {
        if (vec_[i] - vec_[i - 1] < min)
            min = vec_[i] - vec_[i - 1];
    }
    return (min);
}

int Span::longestSpan()
{
    int max;

    if (vec_.size() <= 1)
        throw std::runtime_error("Span is too short");
    std::sort(vec_.begin(), vec_.end());
    max = *vec_.rbegin() - *vec_.begin();
    return (max);
}