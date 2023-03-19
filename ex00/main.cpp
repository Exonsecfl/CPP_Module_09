#include "btc.hpp"

// --------------------------------------------------------------------------------------------
s_line lineSplit (std::string line, s_line split)
{
	// initialisation de la structure
	split.date = "";
	split.value = "";
	split.comment = "";
	split.value_d = 0;
	bool valueTreated = false;

	// extraction de la date
	split.date = (line.substr(0, 10));
	// extraction de la valeur
	if (line.substr(10 ,3) == " | ")
	{
		split.value = (line.substr(13, line.length()-13));
		valueTreated = true;
    }
	if (line.substr(10 ,1) == ",")
	{
		split.value = (line.substr(11, line.length()-11));
		valueTreated = true;
	}
	if (valueTreated == false)
	{
		split.comment = "Error: bad input => " + split.date;
		return(split);
	}

	// check split value
	split.value_d = atof(split.value.c_str());
	// must be positive
	if (split.value_d < 0)
	{
		split.comment = "Error: not a positive number";
		split.value_d = 0;
		return (split);
	}
	// must be less than 1000
	if (split.value_d > 1000)
	{
	split.comment = "Error: too large n number";
	split.value_d = 0;
	return (split);
	}
	return (split);
}

// --------------------------------------------------------------------------------------------
int main (int argc, char* argv[])
{
// initialisation de l'objet BitcoinExchange
	BitcoinExchange tauxBitcoin;
// controle du parametre et traitement des erreur --> input
// -- parametre vide
    if (argc != 2)
	{
        std::cout << RED << "Error: missing file as parameter." << NOC << std::endl;
		return (0);
	}
// ouverture du fichier input et traitement des erreurs

	std::string file = argv[1];
	std::fstream inputFile;
	inputFile.open(file.c_str());
	if (!inputFile.is_open()) 
	{
// -- fichier manquant		
		std::cout << RED << "Error: could not open file." << NOC << std::endl;
		return (0);
	}
	else
	{
// -- on peut continuer 
	std::string line;
	s_line split;
//  la premiere ligne est la description du fichier, elle est passee outre pour la conversion
	getline(inputFile, line);
//  comme le fichier input existe, passage au chargement des taux

//  chargement des taux
	std::fstream dataFile;
	dataFile.open("data.csv");	
	if (!dataFile.is_open()) 
	{
// -- fichier manquant		
		std::cout << RED << "Error: file data.csv with bitcoin rates missing." << NOC << std::endl;
		return (0);
	}
	getline(dataFile, line);

	// iteration sur les taux pour le chargement de taux_bitcoin
	while (getline(dataFile, line))
	{
		split = lineSplit(line, split);
		tauxBitcoin.setBitcoinExchange(split.date, split.value_d);
	}
	dataFile.close();	


// chargement des operations selon le fichier input
//  traitement des lignes suivantes
	double tauxForCalc;
	while (getline(inputFile, line)) 
	{
			split = lineSplit(line, split);
			if (split.comment == "")
			{
			tauxForCalc = tauxBitcoin.getBitcoinExchange(split.date);
			std::cout << split.date << " => " << split.value_d << " = " << (tauxForCalc * split.value_d) <<  std::endl;
			}
			else
			{
			std::cout << RED << split.comment << NOC << std::endl;
			}
		}
	}
	inputFile.close();	
}


