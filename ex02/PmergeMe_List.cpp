#include "PmergeMe_List.hpp"

PmergeMe_List::PmergeMe_List(int argc, char *argv[]): _size(argc -1)
{
    // Check parameters

    if (_size == 0)
    {
        std::cerr << "Erreur: arguments expected" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0 ; i < _size ; i++)
    {
        int valeur = atoi(argv[i]);
        if (valeur <= 0)
        {
            valeur *= -1;
            //std::cerr << "Erreur: negative value" << std::endl;
            //exit(EXIT_FAILURE);
        }

        _bucket.push_back(valeur);
    }
}

PmergeMe_List::~PmergeMe_List() {}

void PmergeMe_List::test()
{
    // print unsorted list
    std::cout << "Before: ";

    std::list <int>::iterator bucketIterator = _bucket.begin();

    for (bucketIterator = _bucket.begin() ; bucketIterator != _bucket.end() ; bucketIterator++)
    {
        std::cout << *bucketIterator << " ";
    }
    std::cout << std::endl<< std::endl;

    _bucket.sort();

    // print unsorted list
    std::cout << "After: ";

    bucketIterator = _bucket.begin();

    for (bucketIterator = _bucket.begin() ; bucketIterator != _bucket.end() ; bucketIterator++)
    {
        std::cout << *bucketIterator << " ";
    }
    std::cout << std::endl<< std::endl;
}