#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> avVec) : _avVec(avVec)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_avVec = src._avVec;
        this->_res = src._res;
    }
    return (*this);
}

std::vector<int> PmergeMe::generateJacobsthalIndex(size_t size)
{
    std::vector<int> indexes;
    int jacobsthalSequence[size + 1];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int lastJacobsthalNumber = 2;
    indexes.push_back(0);
    indexes.push_back(1);

    for (size_t i = 2; indexes.size() < size; i++)
    {
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        if(i != 2)
        {
            indexes.push_back(jacobsthalSequence[i]);

        }

        for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
            indexes.push_back(j);
        lastJacobsthalNumber = jacobsthalSequence[i];
    }
    return (indexes);
}

void PmergeMe::printData()
{
    std::cout << "Before: ";
    for(size_t i = 0; i < _avVec.size(); i++)
        std::cout << _avVec[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for(size_t i = 0; i < _res.size(); i++)
        std::cout << _res[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of  " << _avVec.size() << " elements";
    std::cout << " with std::vector: " << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of  " << _avVec.size() << " elements";
    std::cout << " with std::deque: " << _dequeTime << " us" << std::endl;
}

void PmergeMe::run()
{
    try
    {
        sortVec();
        sortDeque();
        printData();
    }
    catch (std::exception &e)
    {
        std::cout << "Error" << std::endl;
    }
}


/*#########################################################################
#                                   Vector                                #
#########################################################################*/


int PmergeMe::binarySearchVec(std::vector<int> &res, int target)
{
    int left = 0;
    int right = res.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (res[mid] == target)
            return (mid);
        if (res[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

void PmergeMe::insertionPendingElementVec(std::vector<std::pair<int, int> > &mainChain, std::vector<int> &res)
{
    std::vector<int> jacobsthalIndex = generateJacobsthalIndex(mainChain.size());

    for (size_t i = 0; i < jacobsthalIndex.size(); i++)
    {
        size_t index = jacobsthalIndex[i];
        if (index >= mainChain.size())
            continue ;
        int insertIndex = binarySearchVec(res, mainChain[index].second);
        res.insert(res.begin() + insertIndex, mainChain[index].second);
    }
}

void PmergeMe::sortMainChainVec(std::vector<std::pair<int, int> > &mainChain)
{
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = i + 1; j < mainChain.size(); j++)
        {
            if (mainChain[i].first > mainChain[j].first)
            {
                std::pair<int, int> temp = mainChain[i];
                mainChain[i] = mainChain[j];
                mainChain[j] = temp;
            }
        }
    }
}

std::vector<std::pair<int, int> > PmergeMe::makeChainVec()
{
    std::vector<std::pair<int, int> > mainChain;
    std::vector<int> input = _avVec;

    for (size_t i = 0; i < input.size(); i++)
    {
        std::pair<int, int> p;
        if (i + 1 == input.size())
        {
            p.first = INT_MAX;
            p.second = input[i];
            mainChain.push_back(p);
            break ;
        }

        if (input[i] > input[i + 1])
        {
            p.first = input[i];
            p.second = input[i + 1];
            mainChain.push_back(p);
            i++;
        }
        else
        {
            p.first = input[i + 1];
            p.second = input[i];
            mainChain.push_back(p);
            i++;
        }
    }
    return (mainChain);
}

void PmergeMe::sortVec()
{
    std::vector<int> res;
    std::vector<std::pair<int, int > > mainChain;

    std::clock_t start = std::clock();

    mainChain = makeChainVec();
    sortMainChainVec(mainChain);
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        if (mainChain[i].first == INT_MAX)
            break ;
        res.push_back(mainChain[i].first);
    }
    insertionPendingElementVec(mainChain, res);
    _res = res;

    std::clock_t end = std::clock();
    double elapsed_us = (end - start) / (double)CLOCKS_PER_SEC * 1e6;
    _vecTime = elapsed_us;
}

/*#########################################################################
#                                   Vector                                #
#########################################################################*/




/*#########################################################################
#                                   Deque                                 #
#########################################################################*/

int PmergeMe::binarySearchDeque(std::deque<int> &res, int target)
{
    int left = 0;
    int right = res.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (res[mid] == target)
            return (mid);
        if (res[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

void PmergeMe::insertionPendingElementDeque(std::deque<std::pair<int, int> > &mainChain, std::deque<int> &res)
{
    std::vector<int> jacobsthalIndex = generateJacobsthalIndex(mainChain.size());

    for (size_t i = 0; i < jacobsthalIndex.size(); i++)
    {
        size_t index = jacobsthalIndex[i];
        if (index >= mainChain.size())
            continue ;
        int insertIndex = binarySearchDeque(res, mainChain[index].second);
        res.insert(res.begin() + insertIndex, mainChain[index].second);
    }
}

void PmergeMe::sortMainChainDeque(std::deque<std::pair<int, int> > &mainChain)
{
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = i + 1; j < mainChain.size(); j++)
        {
            if (mainChain[i].first > mainChain[j].first)
            {
                std::pair<int, int> temp = mainChain[i];
                mainChain[i] = mainChain[j];
                mainChain[j] = temp;
            }
        }
    }
}

std::deque<std::pair<int, int> > PmergeMe::makeChainDeque()
{
    std::deque<std::pair<int, int> > mainChain;
    std::vector<int> input = _avVec;

    for (size_t i = 0; i < input.size(); i++)
    {
        std::pair<int, int> p;
        if (i + 1 == input.size())
        {
            p.first = INT_MAX;
            p.second = input[i];
            mainChain.push_back(p);
            break ;
        }

        if (input[i] > input[i + 1])
        {
            p.first = input[i];
            p.second = input[i + 1];
            mainChain.push_back(p);
            i++;
        }
        else
        {
            p.first = input[i + 1];
            p.second = input[i];
            mainChain.push_back(p);
            i++;
        }
    }
    return (mainChain);
}

void PmergeMe::sortDeque()
{
    std::deque<int> res;
    std::deque<std::pair<int, int > > mainChain;

    std::clock_t start = std::clock();

    mainChain = makeChainDeque();
    sortMainChainDeque(mainChain);
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        if (mainChain[i].first == INT_MAX)
            break ;
        res.push_back(mainChain[i].first);
    }
    insertionPendingElementDeque(mainChain, res);

    std::clock_t end = std::clock();
    double elapsed_us = (end - start) / (double)CLOCKS_PER_SEC * 1e6;
    _dequeTime = elapsed_us;
}

/*#########################################################################
#                                   Deque                                 #
#########################################################################*/