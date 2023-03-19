#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

# include <iostream>
# include <map>
# include <algorithm>

class BitcoinExchange 
{
    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &str);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);

        void setBitcoinExchange(std::string date, double BitcoinExchange);
        double getBitcoinExchange(std::string);
    private:
        std::multimap <std::string, double> _BitcoinExchange;      
       
};


#endif