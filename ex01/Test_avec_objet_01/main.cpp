//#include "RPN.hpp"
#include "rpn_main.hpp"
int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << RED << "Erreur - parametre unique requis ./RPN \"7 7 * 7 -\"" << NOC << std::endl;
        return (0);
    }

    std::string operationRpn = argv[1];

    // declaration de l'objet RPN
    RPN objRPN;

    // parsing
    std::string temp;
    std::string arg;
    bool status;
    int pos = 0;
    while (operationRpn.length() != 0)
    {
        pos = operationRpn.find(" ");
        // pas de blanc trouve, argument final, il est gere
        // c'est obligatoirement une operande
        if (pos == -1)
        {
            arg = operationRpn;
            std::cout << "argument " << arg << std::endl;

            if (objRPN.setValue(arg) == 1)
            {
                return (0);
            }
            
            objRPN.setValue("quit");
            
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

            status = objRPN.setValue(arg);

            switch (status)
            {
            case 0:
                temp = operationRpn.substr(pos, operationRpn.length()-pos);
                operationRpn = temp;
                break;
            case 1:
                return (0);
            }
        }
    }
}
