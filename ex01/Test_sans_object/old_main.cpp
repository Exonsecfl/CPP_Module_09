#include "rpn.hpp"

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << RED << "Erreur - parametre unique requis ./RPN \"7 7 * 7 -\"" << NOC << std::endl;
        return (0);
    }


    std::string operationRpn = argv[1];

    // recherche de parantese, erreur redibitoire
    int posPO = operationRpn.find("(");
    int posPF = operationRpn.find(")");
    if (posPO != -1 || posPF != -1)
    {
        std::cout << RED << "Erreur - parenthese non autorisees" << NOC << std::endl;
        return (0);
    }
    
    // creation de la queue
    std::queue<std::string> rpn;    
    // parsing
    std::string temp;
    std::string arg;
    int pos = 0;
    while (operationRpn.length() != 0)
    {
        pos = operationRpn.find(" ");
        // pas de blanc trouve, argument final, il est gere
        // c'est obligatoirement une operande
        if (pos == -1)
        {
            arg = operationRpn;
            rpn.push(arg);
            std::cout << "argument final " << arg << std::endl;
            operationRpn = "";
        }
        // premiere position est un blanc, on le supprime
        else if (pos == 0)
        {
            temp = operationRpn.substr(1, operationRpn.length()-1);
            operationRpn = temp;
        }
        // le blanc est plus loin, c'est un parametre
        // de type oeration ou operande
        else
        {
            arg = operationRpn.substr(0, pos);
            std::cout << "argument " << arg << std::endl;
            rpn.push(arg);
            temp = operationRpn.substr(pos, operationRpn.length()-pos);
            operationRpn = temp;
        }

    }

    // extraction de la queue et calculation
    std::cout << "Calculation selon la methode NPI (RPN) : " << std::endl;
    bool firstNb = true;
    double operande = 0;
    double result = 0;
    double resultatPrecedent = 0;
    while (!rpn.empty())
    {
        std::string value = rpn.front();
        rpn.pop();
        // Initialisation du calcul
        if (firstNb == true)
        {
            operande = atof(value.c_str());
            result = operande;
            std::cout << result << " = " << operande << std::endl;

            firstNb = false;
        }
        // Etapes subsequentes
        else
        {
            std::string operande = value;
            std::string operateur = rpn.front();
            rpn.pop();
            resultatPrecedent = result;
            bool traitementOK = false;
            // identification de l'operateur
            if (operateur == "+")
            {
                result = result + atof(operande.c_str());
                std::cout << result << " = " << resultatPrecedent << " + " <<  operande <<  std::endl;
                traitementOK = true;
            }
            // identification de l'operateur
            if (operateur == "-")
            {
                result = result - atof(operande.c_str());
                std::cout << result << " = " << resultatPrecedent << " - " <<  operande <<  std::endl;
                traitementOK = true;
            }
            // identification de l'operateur
            if (operateur == "*")
            {
                result = result * atof(operande.c_str());
                std::cout << result << " = " << resultatPrecedent << " * " <<  operande <<  std::endl;
                traitementOK = true;
            }
            // identification de l'operateur
            if (operateur == "/")
            {
                result = result / atof(operande.c_str());
                std::cout << result << " = " << resultatPrecedent << " / " <<  operande <<  std::endl;
                traitementOK = true;
            }
            if (traitementOK == false)
            {
            std::cout << RED << "Erreur : ne suis pas la methodologie NPI (RPN)" << NOC << std::endl;
            std::cout << 0 << std::endl;
            return (0);
            }
        }
    } 

    std::cout << result << std::endl;

}
