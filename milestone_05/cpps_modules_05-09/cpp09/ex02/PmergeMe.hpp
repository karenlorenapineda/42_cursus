#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <utility>
#include <vector>
#include <ctime>
#include <deque>

class PmergeMe
{
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	void sortVector();
	void sortDeque();

public:
	PmergeMe();
	PmergeMe(const PmergeMe& src);
	~PmergeMe();

	PmergeMe& operator=(const PmergeMe& src);

	void parseInput(int ac, char** av);
	void sort();
	void displayBefore() const;
	void displayAfter() const;
};

#endif