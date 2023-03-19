#include "rpn_main.hpp"

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << RED << "Erreur - parametre unique requis ./RPN \"7 7 * 7 -\"" << NOC << std::endl;
        return (0);
    }

    std::string parametre = argv[1]; // valeur intermediaire qui supportera la decroissance

    // declaration de l'objet RPN
    RPN objRPN;

    // parsing
    std::string temp; // pour la reduction de taille du parametre
    std::string arg; // envoye a l'objet (nombre, operateur, quit, ou encore extraction erronee)
    bool status; // status en retour de fonction

    int pos = 0; // position dans le parametre

    // boucle sur le parametre jusqu'a l'obtention d'une longeur = 0
    while (parametre.length() != 0)
    {
        pos = parametre.find(" ");

        // pas de blanc trouve, argument final
        if (pos == -1)
        {
            arg = parametre;

            status = objRPN.setValue(arg);
            if (status == 1)
            {
                //std::cout << "Erreur : calcul interrompu-1.";
                return (0);
            }            
            else
            {
                status = objRPN.setValue("quit");
                if (status == 1)
                {
                    //std::cout << "Erreur : calcul interrompu-2.";
                    return (0);
                }

            }
            
            parametre = "";
        }
        // premiere position est un blanc, on le supprime
        else if (pos == 0)
        {
            temp = parametre.substr(1, parametre.length()-1);
            parametre = temp;
            // traite le cas du blanc final unique
            if (parametre == "")
                status = objRPN.setValue("quit");
        }
        // le blanc est plus loin, c'est un parametre
        else
        {
            arg = parametre.substr(0, pos);
            temp = parametre.substr(pos, parametre.length()-pos);
            parametre = temp;

            status = objRPN.setValue(arg);

            if (status == 1)
            {
                //std::cout << "Erreur : calcul interrompu-3.";
                return (0);
            }


        }
    }
}
