#ifndef PMERGEME_VECTOR
# define PMERGEME_VECTOR

#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>


class PmergeMe_Vector
{
    public:
        PmergeMe_Vector(int argc, char *argv[]);
        ~PmergeMe_Vector();
        void test(void);

    private:
        PmergeMe_Vector();
        PmergeMe_Vector(PmergeMe_Vector const &src);
        PmergeMe_Vector &operator=(PmergeMe_Vector const &rhs);

        std::vector<int> _bucket;
        
        int _size;

};

# endif
