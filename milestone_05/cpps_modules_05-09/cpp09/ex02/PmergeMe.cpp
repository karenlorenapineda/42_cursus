#include "PmergeMe.hpp"
#include <algorithm>

static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::sortVector()
{
    if (_vec.size() <= 1)
        return;
    
    bool hasOdd = (_vec.size() % 2 != 0);
    int oddElement = hasOdd ? _vec.back() : 0;
    
    if (hasOdd)
        _vec.pop_back();

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vec.size(); i += 2)
    {
        if (_vec[i] > _vec[i + 1])
            pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
        else
            pairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
    }

    _vec.clear();
    for (size_t i = 0; i < pairs.size(); i++)
    {
        _vec.push_back(pairs[i].first);
    }
    
    sortVector();

    // CORRECCIÓN 1: Manejo seguro de duplicados para Vector
    std::vector<bool> used(pairs.size(), false);
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < _vec.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].first == _vec[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> mainChain, pend;
    for (size_t i = 0; i < sortedPairs.size(); i++)
    {
        mainChain.push_back(sortedPairs[i].first);
        pend.push_back(sortedPairs[i].second);
    }
    
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    size_t jIndex = 3;
    size_t lastJ = 1;
    while (lastJ < pend.size())
    {
        size_t currJ = jacobsthal(jIndex);
        if (currJ > pend.size())
            currJ = pend.size();

        for (size_t i = currJ; i > lastJ; i--)
        {
            int element = pend[i - 1];
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
            mainChain.insert(pos, element);
        }
        lastJ = currJ;
        jIndex++;
    }

    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }

    _vec = mainChain;
}

void PmergeMe::sortDeque()
{
    if (_deq.size() <= 1)
        return;
    
    bool hasOdd = (_deq.size() % 2 != 0);
    int oddElement = hasOdd ? _deq.back() : 0;
    
    // CORRECCIÓN 2: Sacamos el impar antes de la recursión
    if (hasOdd)
        _deq.pop_back();

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _deq.size(); i += 2)
    {
        if (_deq[i] > _deq[i + 1])
            pairs.push_back(std::make_pair(_deq[i], _deq[i + 1]));
        else
            pairs.push_back(std::make_pair(_deq[i + 1], _deq[i]));
    }

    _deq.clear();
    for (size_t i = 0; i < pairs.size(); i++)
    {
        _deq.push_back(pairs[i].first);
    }
        
    sortDeque();

    std::vector<bool> used(pairs.size(), false);
    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < _deq.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].first == _deq[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::deque<int> mainChain, pend;
    for (size_t i = 0; i < sortedPairs.size(); i++)
    {
        mainChain.push_back(sortedPairs[i].first);
        pend.push_back(sortedPairs[i].second);
    }
    
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    size_t jIndex = 3;
    size_t lastJ = 1;
    while (lastJ < pend.size())
    {
        size_t currJ = jacobsthal(jIndex);
        if (currJ > pend.size())
            currJ = pend.size();

        for (size_t i = currJ; i > lastJ; i--)
        {
            int element = pend[i - 1];
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
            mainChain.insert(pos, element);
        }
        lastJ = currJ;
        jIndex++;
    }

    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }

    _deq = mainChain;
}

void PmergeMe::sort()
{
    displayBefore();

    clock_t startVec = clock();
    sortVector();
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeq = clock();
    sortDeque();
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    displayAfter();

    std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for(size_t i = 0; i < _vec.size(); i++)
    {
        if (i == 5 && _vec.size() > 5)
        {
            std::cout << "[...] ";
            break;
        }
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After: ";
    for(size_t i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) : _vec(src._vec), _deq(src._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deq = src._deq;
    }
    return *this;
}

void PmergeMe::parseInput(int ac, char** av)
{
    if (ac < 2) 
        throw std::runtime_error("Error: dynamic arguments required.");

    for (int i = 1; i < ac; i++)
    {
        if (av[i][0] == '\0')
            throw std::runtime_error("Error: empty argument");

        char* endptr;
        long num = std::strtol(av[i], &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Error: invalid input.");
        if (num <= 0)
            throw std::runtime_error("Error: only positive integers.");
        if (num > 2147483647)
            throw std::runtime_error("Error: integer overflow.");
        
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }
}