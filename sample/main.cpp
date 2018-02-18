#include <iostream>
#include <algorithm> 
#include <random> 
#include <iterator>
#include "shell_sort.h"
using namespace std;
int main(int argc, char* argv[]){

	if(argc < 2){
		cout << "enter size array!!!";
		return -1;
	}
	int size_array = atoi(argv[1]); 
	vector<int> test_data(size_array);
	mt19937 generator{random_device()()};
	uniform_int_distribution<> distribution(1, 100);
	
	generate(test_data.begin(), test_data.end(), [&distribution, &generator](){
							return distribution(generator);
							});
				 		
	copy(test_data.begin(), test_data.end(), ostream_iterator<int>(cout, " "));
	cout << endl;	
	auto start = Time::now();
	shell_sort(test_data.begin(), test_data.end());
	auto end = Time::now();
	fms elapsed_time = end - start;
	cout << elapsed_time.count() << "ms" << endl;
	
	copy(test_data.begin(), test_data.end(), ostream_iterator<int>(cout, " "));
	
	return 0;
}		







