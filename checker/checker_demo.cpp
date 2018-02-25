#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include "checker.h"
using namespace std;

int main(int argc, char* argv[]){
	int total_count_tests = 7;
	Checker checker(total_count_tests);

	if(argc > 1){
		int num_test; 	
		for(int i = 1; i < argc; ++i){
			num_test = atoi(argv[i]);
			checker.run_tests(num_test);
		}
	}else{
		checker.run_tests();
	}

	return 0;
}
