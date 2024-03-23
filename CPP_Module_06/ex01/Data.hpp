#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
    private :
        int val;
    
    public :
        Data();
        Data(int val);
        Data(const Data &other);
        Data &operator=(const Data &other);
        ~Data();

        int getVal() const;
};

#endif