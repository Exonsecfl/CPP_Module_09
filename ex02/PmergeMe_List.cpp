#include "PmergeMe_List.hpp"

PmergeMe_List::PmergeMe_List(int argc, char *argv[]): _size(argc -1)
{
    // Check parameters

    if (_size == 0)
    {
        std::cout << "Erreur: arguments expected" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 1 ; i < argc ; i++)
    {
        int valeur = atoi(argv[i]);
        if (valeur < 0)
        {
            std::cout << "Erreur: negative value" << std::endl;
            exit(EXIT_FAILURE);
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

    // print sorted list
    std::cout << "After: ";

    bucketIterator = _bucket.begin();

    for (bucketIterator = _bucket.begin() ; bucketIterator != _bucket.end() ; bucketIterator++)
    {
        std::cout << *bucketIterator << " ";
    }
    std::cout << std::endl<< std::endl;
}