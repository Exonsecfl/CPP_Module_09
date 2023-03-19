#ifndef RPN_CLASS
# define RPN_CLASS

#define		RED	"\033[31;1m"
#define		GRE	"\033[32;1m"
#define		YEL	"\033[33;1m"
#define		BLU	"\033[34;1m"
#define		NOC "\033[0m"


#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>



class RPN
{
    public:

        RPN (void);
        ~RPN (void);
        RPN (RPN const &src);
        RPN &operator=(RPN const &rhs);

        bool setValue (std::string arg);

        

    private:
        std::stack<double> _rpn;

        bool isOperator (const std::string &arg);
        bool setCalculation (const std::string &arg);
     


};


#endif