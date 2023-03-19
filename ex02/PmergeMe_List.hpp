#ifndef PMERGEME_LIST
# define PMERGEME_LIST

#include <iostream>
#include <cstdlib>
#include <list>

class PmergeMe_List
{
    public:
        PmergeMe_List(int argc, char *argv[]);
        ~PmergeMe_List();
        void test(void);

    private:
        PmergeMe_List();
        PmergeMe_List(PmergeMe_List const &src);
        PmergeMe_List &operator=(PmergeMe_List const &rhs);

        std::list<int> _bucket;
        
        int _size;

};

# endif
