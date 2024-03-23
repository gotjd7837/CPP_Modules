#include "Data.hpp"

Data::Data() : val(0) 
{

}

Data::Data(int val) : val(val)
{

}

Data::Data(const Data &other) : val(other.val)
{

}

Data &Data::operator=(const Data &other)
{
    this->val = other.val;
    return *this;
}

Data::~Data() {}

int Data::getVal() const
{
    return (this->val);
}
