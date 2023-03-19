#ifndef BTC
# define BTC


#define		RED	"\033[31;1m"
#define		GRE	"\033[32;1m"
#define		YEL	"\033[33;1m"
#define		BLU	"\033[34;1m"
#define		NOC "\033[0m"


#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "BitcoinExchange.hpp"

// Structure to hold the date and de value/echange rate
struct s_line {
    std::string date;
    std::string value;
    std::string comment;
    double value_d;
};

#endif