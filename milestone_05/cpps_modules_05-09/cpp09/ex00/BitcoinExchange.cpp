/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 19:26:57 by kpineda-          #+#    #+#             */
/*   Updated: 2026/07/04 19:26:58 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap)
        daysInMonth[2] = 29;
    return day <= daysInMonth[month];
}

bool BitcoinExchange::isValidValue(const std::string& value, float& result) const
{
    std::istringstream iss(value);
    if(!(iss >> result))
        return false;
    char residual;
    if (iss >> residual)
        return false;
    return true;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&  src)
{
    if (this != &src)
        this->_database = src._database;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file (filename.c_str());
    if(!file.is_open())
        throw std::runtime_error("Error: could not open database file");
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos) continue;

        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);

        float rate;
        std::istringstream iss(rateStr);
        if (iss >> rate)
            _database [date] = rate;
    }
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pipe = line.find("|");
        if (pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipe));
        std::string valueStr = trim(line.substr(pipe + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value))
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _database.lower_bound(date);
        if(it == _database.end() || it->first != date)
        {
            if (it == _database.begin())
            {
                std::cerr << "Error: date too early => " << date << std::endl;
                continue;
            }
            --it;
        }

        float rate = it->second;
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}