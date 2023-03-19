#include "PmergeMe_Vector.hpp"

PmergeMe_Vector::PmergeMe_Vector(int argc, char *argv[]): _size(argc -1)
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

PmergeMe_Vector::~PmergeMe_Vector() {}

void PmergeMe_Vector::test()
{
    // print unsorted list
    std::cout << "Before: ";

    std::vector <int>::iterator bucketIterator = _bucket.begin();

    for (bucketIterator = _bucket.begin() ; bucketIterator != _bucket.end() ; bucketIterator++)
    {
        std::cout << *bucketIterator << " ";
    }
    std::cout << std::endl<< std::endl;

    sort(_bucket.begin(), _bucket.end());

    // print unsorted list
    std::cout << "After: ";

    bucketIterator = _bucket.begin();

    for (bucketIterator = _bucket.begin() ; bucketIterator != _bucket.end() ; bucketIterator++)
    {
        std::cout << *bucketIterator << " ";
    }
    std::cout << std::endl<< std::endl;
}