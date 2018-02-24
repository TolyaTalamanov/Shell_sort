#include "checker.h"
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
using namespace std;

void load_data_from_file(string file_path);

int main(int argc, char* argv[]){
	string input_data_path  = argv[1];
	string output_data_path = argv[2];
	
	Checker checker;

	auto input_data  = load_data_from_file(output_data_path);
	auto output_data = load_data_from_file(output_data_path);

	
	

}
void load_data_from_file(string file_path){
	ifstream data_file(file_path);
	vector<int> data;
	istream_iterator<int> begin_file(data_file);
	istream_iterator<int> end_file;
	copy(begin_file, end_file, back_inserter(data));
}

