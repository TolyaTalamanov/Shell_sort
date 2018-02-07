#include <iostream>
#include <algorithm> 
#include <random> 
#include <iterator>
#include "shell_sort.h"
using namespace std;
int main(){
	vector<int> test_data(10);
	mt19937 generator{random_device()()};
	uniform_int_distribution<> distribution(1, 100);
	
	generate(test_data.begin(), test_data.end(), [&distribution, &generator](){
							return distribution(generator);
							});
				 		
	copy(test_data.begin(), test_data.end(), ostream_iterator<int>(cout, " "));
	cout << endl;	
	shell_sort(test_data.begin(), test_data.end());
	
	copy(test_data.begin(), test_data.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}		







