#ifndef SHELL_LIB_INCLUDE_SHELL_SORT_H
#define SHELL_LIB_INCLUDE_SHELL_SORT_H

#include <iostream>
#include <algorithm> 
#include <random> 
#include <iterator>
#include <vector>
#include <chrono>

using Time = std::chrono::high_resolution_clock;
using ms   = std::chrono::milliseconds;
using fms  = std::chrono::duration<float, std::milli>;

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

int get_sedjvik_element(int s)
{
	return (s % 2 == 0) ? (9 * (1 << s)	- 9 * (1 <<  (s / 2)     ) + 1)
						: (8 * (1 << s) - 6 * (1 << ((s + 1) / 2)) + 1);
}

std::vector<int> get_sedjvik_distances(int size_array)
{
	std::vector<int> distances;
	int s = 0;
	do{
		distances.emplace_back(get_sedjvik_element(s));
		++s;
	} while(3 * distances.back() < size_array);
	distances.pop_back();
	return distances;
}

template<typename Iterator>
void shell_sort(Iterator first, Iterator last)
{
	if (!(first < last))
        return;
	
	int  size_array     = std::distance(first, last);
	auto distances      = get_sedjvik_distances(size_array);
	
	std::for_each(distances.rbegin(), distances.rend(),
				[&first, &last](const auto& increment){
					insert_sort_with_increment(first, last, increment);
				});
}

#endif //SHELL_LIB_INCLUDE_SHELL_SORT_H
