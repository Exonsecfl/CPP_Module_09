#include <iostream>
#include <iomanip>
#include "PmergeMe_List.hpp"
#include "PmergeMe_Vector.hpp"

#define		RED	"\033[31;1m"
#define		GRE	"\033[32;1m"
#define		YEL	"\033[33;1m"
#define		BLU	"\033[34;1m"
#define		NOC "\033[0m"

int main(int argc, char *argv[])
{
    // comparaison from https://www.educba.com/c-plus-plus-vector-vs-list/

    // ---- STD::LIST ---
    // List in C++ stores the elements at the non-contiguous memory location. It is considered a doubly linked list internally.
    // Insertion and deletion of elements in List at any position take constant time as it involves the use of pointers and their swapping.
    // List does not have any fixed size or a default size as it is a doubly-linked list and can be resized upon insertion or deletion.
    // Memory required to store the elements in the List is comparatively large as it holds the element as well as the pointers for the
    // next and previous nodes.
    // Random access of elements in the List is not possible as it is implemented as the doubly linked list. Programmers need to access 
    // the elements by traversing through the pointers.
    // In case of List, iterators remain valid even if the elements are inserted or deleted from it.

    // declanchement du temps
    clock_t begin_list = clock();

    // declaration de l'objet contenant la std::list
    PmergeMe_List bucketList(argc, argv);
    bucketList.test();

    // prise du temps de fin et calculation
    clock_t end_list = clock();
    double time_spend_list = double(end_list - begin_list) / CLOCKS_PER_SEC;
    
    // ----------------------------------------------------------------------------------------
    // ---- STD::VECTOR ---
    // A vector in C++ stores the elements at the contiguous memory location. It is considered to be a type of dynamic array internally.
    // Insertion and deletion of elements at the last take constant time but insertion and deletion elsewhere (in the starting or middle)
    // takes a lot of time as the array needs to be traversed.
    // Vector is a dynamic array and has the default size.
    // Memory required to store the elements in the Vector is lesser than List as it uses memory for the element only.
    // As the elements in Vector are stored sequentially like an array, so the elements can be accessed randomly by providing the index
    // number only.
    // Iterators become invalid when the elements are deleted or inserted from it.

    // declanchement du temps
    clock_t begin_vector = clock();

    // declaration de l'objet contenant la std::list
    PmergeMe_Vector bucketVector(argc, argv);
    bucketVector.test();

    // prise du temps de fin et calculation
    clock_t end_vector = clock();
    double time_spend_vector = double(end_vector - begin_vector) / CLOCKS_PER_SEC;
    

    // ----------------------------------------------------------------------------------------
    // --- RESULTATS --
    std::cout << YEL << "Time to process a range of " << argc -1 << " elements with " << GRE << "std::list" << YEL << ": " << std::fixed << std::setprecision(6) << time_spend_list * 1000000 << " us" << NOC << std::endl;
    std::cout << std::endl;

    std::cout << YEL << "Time to process a range of " << argc -1 << " elements with " << GRE << "std::vector"<< YEL << ": " << std::fixed << std::setprecision(6) << time_spend_vector * 1000000 << " us" << NOC << std::endl;
    std::cout << std::endl;
}