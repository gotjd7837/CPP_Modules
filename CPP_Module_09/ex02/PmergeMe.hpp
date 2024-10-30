#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <stdlib.h>
# include <vector>
# include <sstream>
# include <string>
# include <cstring>
# include <deque>
# include <utility>
# include <climits>
# include <ctime>




class PmergeMe
{
    public:
        std::vector<int> _avVec;
        std::vector<int> _res;
        double _vecTime;
        double _dequeTime;

        PmergeMe();

        void sortVec();
        void sortDeque();

        void printData();
        std::vector<int> generateJacobsthalIndex(size_t size);

        //vector
        std::vector<std::pair<int, int> > makeChainVec();
        void sortMainChainVec(std::vector<std::pair<int, int> > &mainChain);
        void insertionPendingElementVec(std::vector<std::pair<int, int> > &mainChain, std::vector<int> &res);
        int binarySearchVec(std::vector<int> &res, int target);

        //deque
        std::deque<std::pair<int, int> > makeChainDeque();
        void sortMainChainDeque(std::deque<std::pair<int, int> > &mainChain);
        void insertionPendingElementDeque(std::deque<std::pair<int, int> > &mainChain, std::deque<int> &res);
        int binarySearchDeque(std::deque<int> &res, int target);

    public:
        PmergeMe(std::vector<int> avVec);
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        void run();

};

#endif