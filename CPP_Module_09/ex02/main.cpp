#include "PmergeMe.hpp"

bool validateInput(const std::string& s) {
    char *ptr = NULL;
    double value = std::strtod(s.c_str(), &ptr);
    if (value == 0.0 && !std::isdigit(s[0]))
        return false;
    if (*ptr && std::strcmp(ptr, "f") != 0)
        return false;
    if (value < 0)
        return false;
    if (value >= INT_MAX)
        return false;
    return (value == static_cast<int>(value));
}

std::vector<int> argvToVector(int ac, char **av)
{
    std::vector<int> res;

    if (ac < 2 || (ac == 2 && std::string(av[1]) == ""))
    {
        std::cout << "Error" << std::endl;
        return (res);
    }

    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(av[i]);
        std::string s;
        while (std::getline(ss, s, ' '))
        {
            if (s == "")
                continue ;
            if (!validateInput(s))
            {
                std::cout << "Error" << std::endl;
                return (std::vector<int>());
            }
            res.push_back(std::strtod(s.c_str(), NULL));
        }
    }
    return (res);

}

int main(int ac, char **av)
{
    std::vector<int> avVec = argvToVector(ac, av);
    if (avVec.empty())
        return 1;

    PmergeMe p(avVec);
    p.run();

    return 0;
    
}