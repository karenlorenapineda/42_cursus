/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 19:26:54 by kpineda-          #+#    #+#             */
/*   Updated: 2026/07/04 19:26:55 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <map>

class BitcoinExchange
{
    std::map<std::string, float> _database;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value, float& result) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange&  src);

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
};

#endif