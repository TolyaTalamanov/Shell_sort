#ifndef SHELL_LIB_INCLUDE_SHELL_SORT_H
#define SHELL_LIB_INCLUDE_SHELL_SORT_H

#include <iostream>
#include <algorithm> 
#include <random> 
#include <iterator>
#include <vector>

template<typename Iterator>
void insert_sort_with_increment(Iterator first, Iterator last, int increment)
{
    for (auto i = first + increment; i != last; ++i)
        for (auto j = i; j != first && *j < *(j - increment); --j)
            std::iter_swap(j - increment, j);
}

template<typename Iterator>
void insert_sort(Iterator first, Iterator last)
{
	if (!(first < last))
        return;
	insert_sort_with_increment(first, last, 1);
}

#endif //SHELL_LIB_INCLUDE_SHELL_SORT_H

