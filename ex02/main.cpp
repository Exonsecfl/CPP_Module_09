#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include "PmergeMe_List.hpp"
#include "PmergeMe_Vector.hpp"

#define		RED	"\033[31;1m"
#define		GRE	"\033[32;1m"
#define		YEL	"\033[33;1m"
#define		BLU	"\033[34;1m"
#define		NOC "\033[0m"

int main(int argc, char *argv[])
{
    // declanchement du temps
    clock_t begin = clock();

    // declaration de l'objet contenant la std::list
    PmergeMe_List bucketList(argc, argv);
    bucketList.test();

    // prise du temps de fin et calculation
    clock_t end = clock();
    double time_spend = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << YEL << "Time to process a range of " << argc -1 << " elements with " << "std::list" << ": " << std::fixed << std::setprecision(6) << time_spend * 1000000 << " us" << NOC << std::endl;
    std::cout << std::endl;
    // ----------------------------------------------------------------------------------------

    // declanchement du temps
    begin = clock();

    // declaration de l'objet contenant la std::list
    PmergeMe_Vector bucketVector(argc, argv);
    bucketVector.test();

    // prise du temps de fin et calculation
    end = clock();
    time_spend = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << YEL << "Time to process a range of " << argc -1 << " elements with " << "std::Vector" << ": " << std::fixed << std::setprecision(6) << time_spend * 1000000 << " us" << NOC << std::endl;
    std::cout << std::endl;

    // ----------------------------------------------------------------------------------------

}