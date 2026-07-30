#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

// Helper function to run a single integration test case
void runTestCase(const std::string& testName, const std::vector<std::string>& arguments, bool shouldFail)
{
    std::cout << "[ RUNNING ] " << testName << std::endl;
    
    int ac = static_cast<int>(arguments.size()) + 1;
    char** av = new char*[ac];
    
    std::string progName = "./PmergeMe";
    av[0] = const_cast<char*>(progName.c_str());
    
    for (size_t i = 0; i < arguments.size(); ++i) {
        av[i + 1] = const_cast<char*>(arguments[i].c_str());
    }

    try 
    {
        PmergeMe program;
        program.parseInput(ac, av);
        program.sort();
        
        if (shouldFail) {
            std::cout << "[ FAILURE ] Test expected an error but passed cleanly." << std::endl;
        } else {
            std::cout << "[ SUCCESS ] Test completed successfully." << std::endl;
        }
    }
    catch (const std::exception& e) 
    {
        if (shouldFail) {
            std::cout << "[ SUCCESS ] Caught expected error: " << e.what() << std::endl;
        } else {
            std::cout << "[ FAILURE ] Unexpected crash/exception: " << e.what() << std::endl;
        }
    }

    delete[] av;
    std::cout << "----------------------------------------------------------------------" << std::endl;
}

std::vector<std::string> generateRandomSequence(size_t count)
{
    std::vector<int> numbers;
    for (size_t i = 1; i <= count * 10; ++i) {
        numbers.push_back(static_cast<int>(i));
    }
    
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    std::random_shuffle(numbers.begin(), numbers.end());
    
    std::vector<std::string> result;
    for (size_t i = 0; i < count; ++i) {
        std::stringstream ss;
        ss << numbers[i];
        result.push_back(ss.str());
    }
    return result;
}

void runAutomatedTestSuite()
{
    std::cout << "======================================================================" << std::endl;
    std::cout << "                    PMERGEME AUTOMATED TEST SUITE                     " << std::endl;
    std::cout << "======================================================================" << std::endl;

    std::cout << "\n[ CATEGORY 1: ERROR HANDLING & EDGE CASES ]\n" << std::endl;
    
    std::vector<std::string> emptyArgs; emptyArgs.push_back("");
    runTestCase("Empty Argument String Check", emptyArgs, true);

    std::vector<std::string> nonNumeric; nonNumeric.push_back("1"); nonNumeric.push_back("2"); nonNumeric.push_back("abc"); nonNumeric.push_back("4");
    runTestCase("Non-Numeric Characters Check", nonNumeric, true);

    std::vector<std::string> floatNum; floatNum.push_back("1"); floatNum.push_back("2.5"); floatNum.push_back("3");
    runTestCase("Floating Point Number Check", floatNum, true);

    std::vector<std::string> negativeNum; negativeNum.push_back("5"); negativeNum.push_back("-3"); negativeNum.push_back("2");
    runTestCase("Negative Integer Check", negativeNum, true);

    std::vector<std::string> zeroNum; zeroNum.push_back("0"); zeroNum.push_back("10"); zeroNum.push_back("20");
    runTestCase("Zero Value Input Check", zeroNum, true);

    std::vector<std::string> overflowNum; overflowNum.push_back("2147483648"); overflowNum.push_back("42");
    runTestCase("Integer Overflow Check (INT_MAX + 1)", overflowNum, true);

    std::cout << "\n[ CATEGORY 2: FUNCTIONAL SORTING VALIDATION ]\n" << std::endl;

    std::vector<std::string> singleItem; singleItem.push_back("42");
    runTestCase("Single Element List (Base Case)", singleItem, false);

    std::vector<std::string> evenList; evenList.push_back("42"); evenList.push_back("8"); evenList.push_back("15"); evenList.push_back("16"); evenList.push_back("23"); evenList.push_back("4");
    runTestCase("Even Number of Elements Sequence", evenList, false);

    std::vector<std::string> oddList; oddList.push_back("3"); oddList.push_back("5"); oddList.push_back("9"); oddList.push_back("7"); oddList.push_back("4");
    runTestCase("Odd Number of Elements Sequence", oddList, false);

    std::vector<std::string> invertedList; invertedList.push_back("6"); invertedList.push_back("5"); invertedList.push_back("4"); invertedList.push_back("3"); invertedList.push_back("2"); invertedList.push_back("1");
    runTestCase("Strictly Inverted Sequence", invertedList, false);

    std::cout << "\n[ CATEGORY 3: STRESS & PERFORMANCE BENCHMARKS ]\n" << std::endl;

    runTestCase("100 Random Elements Benchmark", generateRandomSequence(100), false);
    runTestCase("3000 Random Elements Stress Test", generateRandomSequence(3000), false);
}

int main(int argc, char** argv)
{
    if (argc < 2) 
    {
        runAutomatedTestSuite();
        std::cout << "\nHint: To sort custom numbers, run: ./PmergeMe [int1] [int2] ..." << std::endl;
        return 0;
    }

    try 
    {
        PmergeMe program;
        program.parseInput(argc, argv);
        program.sort();
    }
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}