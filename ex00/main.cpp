#include "btc.hpp"
//
int main (int argc, char* argv[])
{
// controle du parametre et traitement des erreur --> input
// -- parametre vide
    if (argc != 2)
        std::cout << "Error: could not open file.";
// ouverture du fichier input et traitement des erreurs

	std::fstream input_file;
	input_file.open(argv[1]);
	
	if (!input_file) 
	{
// -- fichier manquant		
		std::cout << "Error: could not open file.";
	}
	else
	{
// -- chargement 	
	std::string line;
	while (1) {
			input_file >> line;
			if (input_file.eof())
				break;

			std::cout << line << std::endl;
		}

	}
	input_file.close();	

// -- structure incorrecte
// chargement des operations selon le fichier input
// chargement des taux
// lecture 
}


