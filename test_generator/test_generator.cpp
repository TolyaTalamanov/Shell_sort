#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iterator>
#include<string>
#include"shell_sort.h"
using namespace std;

void writeDataToFile(vector<int> data, const string& file_name);

int main(int argc, char* argv[]){

	const int count_tests = 7;
	const int default_size = 10;
	const int data_size = argv[1] ? atoi(argv[1]) : default_size;

	vector<vector<int>> test_data(count_tests);
	
	test_data[0].resize(data_size);
	fill(test_data[0].begin(), test_data[0].end(), 5);

	test_data[1].resize(data_size);
	iota(test_data[1].begin(), test_data[1].end(), 0);

	test_data[2].resize(data_size);
	iota(test_data[2].rbegin(), test_data[2].rend(), 0);
	
    mt19937 generator{random_device()()};
    uniform_int_distribution<int> distribution(numeric_limits<int>::min(),
                                               numeric_limits<int>::max());
	test_data[3].resize(data_size);
    generate(test_data[3].begin(), test_data[3].end(), [&distribution, &generator](){
        return distribution(generator);
    });

	test_data[4].resize(data_size);
	generate(test_data[4].begin(), test_data[4].end(), [&generator, &distribution](){
				return abs(distribution(generator));
			});

	test_data[5].resize(data_size);
	generate(test_data[5].begin(), test_data[5].end(), [&generator, &distribution](){
				int random_val = distribution(generator);
				return random_val < 0 ? random_val : -1 * random_val; 
			});
	test_data[6].resize(1);
	
	for(int i = 0; i < count_tests; ++i){
		writeDataToFile(test_data[i], "../../test_generator/test_data/" + 
										to_string(i));
		shell_sort(test_data[i].begin(), test_data[i].end());
		writeDataToFile(test_data[i], "../../test_generator/test_data/" + 
										to_string(i) + ".ans");

	}

	return 0;
}
void writeDataToFile(vector<int> data, const string& file_path){
	ofstream file(file_path, ios::binary);
	ostream_iterator<int> file_iterator(file, " ");
	copy(data.begin(), data.end(), file_iterator);
}
