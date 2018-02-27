#include <vector>
#include <algorithm>
#include <iterator>
#include "checker.h"
using namespace std;

vector<int> load_data_from_file(string file_path);

void Checker::run_tests(int num_test){
	string output_data_path = data_dir_path_ + to_string(num_test) + ".ans";

	auto output_data = load_data_from_file(output_data_path);

	if(is_sorted(output_data.begin(), output_data.end())){
		write_message("[ TEST " + to_string(num_test) + " ] AC. Array is sorted.");
	}	
	else{
		write_message("[ TEST " + to_string(num_test) + " ] WA. Array is't sorted.");
	}

}

void Checker::run_tests(){
	for(int num_test = 0; num_test < count_tests_; ++num_test){
		run_tests(num_test);
	}
}

void Checker::write_type(log_params_ param){
	log_file_ << static_cast<int>(param) << std::endl;
}

void Checker::write_verdict(verdict v){
	//write_type(log_params_::VERDICT);
	log_file_ << v;
}

void Checker::write_message(std::string message){
	//write_type(log_params_::MESSAGE);
	log_file_ << message << "\n";
}

vector<int> load_data_from_file(string file_path){
	ifstream data_file(file_path);
	vector<int> data;

	if(!data_file){
		throw runtime_error("failed open file");
	}

	istream_iterator<int> begin_file(data_file);
	istream_iterator<int> end_file;

	copy(begin_file, end_file, back_inserter(data));

	data_file.close();

	return data;
}


