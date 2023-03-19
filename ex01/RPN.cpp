#include "RPN.hpp"

RPN::RPN(void)
{

}

RPN::~RPN(void)
{

}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{   
    if (this != &rhs)
        this->_rpn = rhs._rpn;
    return (*this);
}

bool RPN::setValue (std::string arg)
{
    double nombre;
    bool status;
    // controle si c'est un nombre et chargement dans nombre
    if (std::istringstream(arg) >> nombre)
    {
        this->_rpn.push(nombre);
    }
    // controle si c'est un operateur valide (+ - * /)
    else if (isOperator(arg))
    {
        // operation de calculation
        status = this->setCalculation(arg);
        // si une erreur s'est produite (stack manquant)
        if (status == 1)
        {
            std::cout << RED << "Erreur : resultat incomplet" << NOC << std::endl;
            std::cout << 0 << std::endl;        
            return(1);
        }
    }
    // controle pour la fin du calcul
    else if (arg == "quit")
    {
        // affichage du resultat
        if (this->_rpn.empty() || this->_rpn.size() > 1)
        {
            std::cout << RED << "Erreur : resultat, stack melange operande operateur ou manque l'operateur" << NOC << std::endl;
            std::cout << 0 << std::endl;    
        }
        else
        {
            std::cout << GRE << this->_rpn.top() << NOC << std::endl;
            this->_rpn.pop();
        }
    }
    // erreur de parametre
    else
    {
        std::cout << RED << "Erreur : parametre non supporte" << NOC << std::endl;
        std::cout << 0 << std::endl;
        return (1);
    }
    return (0);
}

bool RPN::isOperator (const std::string &arg)
{
    // controle que l'operateur soit valide
    std::string op[] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++)
    {
        if (arg == op[i])
            return (1);
    }
    return (0);
}

bool RPN::setCalculation (const std::string &arg)
{
    double lVal, rVal, result = 0;
    bool status = false;

    // si le stack est vide, alors segfault
    if (!this->_rpn.empty())
    {
        rVal = this->_rpn.top();
        this->_rpn.pop();
    }
    else
    {
        status = true;
    }
    // si le stack est vide, alors segfault
    if (!this->_rpn.empty())
    {
        lVal = this->_rpn.top();
        this->_rpn.pop();
    }
    else
    {
        status = true;
    }
    // traitement des erreur sur stack
    if (status == true)
    {
        std::cout << RED << "Erreur : calculation" << NOC << std::endl;
        std::cout << 0 << std::endl;
        return (1);
    }
    // effectue les calculs selon l'operateur
    if (arg=="+")
        result = lVal + rVal;
    if (arg=="-")
        result = lVal - rVal;
    if (arg=="*")
        result = lVal * rVal;
    if (arg=="/")
        result = lVal / rVal;        
    // affiche le resultat
    std::cout << result << " = " << lVal << " " << arg << " " <<  rVal <<  std::endl;
    this->_rpn.push(result);
    return (status);

}