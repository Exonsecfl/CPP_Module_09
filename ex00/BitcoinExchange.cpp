#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    // create the map for holding the BitcoinExchange
}

BitcoinExchange::~BitcoinExchange(void)
{
    // destruction
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    if (this != &rhs)
    {
        this->_BitcoinExchange = rhs._BitcoinExchange;
    }
    return (*this);
}

void BitcoinExchange::setBitcoinExchange(const std::string date, const double BitcoinExchange)
{

    this->_BitcoinExchange.insert(std::pair <std::string, double> (date, BitcoinExchange));
    //std::cout << "set " << date << " " << BitcoinExchange << std::endl;
     
}



double BitcoinExchange::getBitcoinExchange(std::string date)
{   
    std::multimap<std::string, double>::iterator it = this->_BitcoinExchange.lower_bound(date);
    
        // reprise de la date suivante si la date n'est pas egale
        if (it->first > date)
        {
            it--;
        }

    double it_value_r = it->second;
    
    return (it_value_r);
}