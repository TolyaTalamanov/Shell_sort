#ifndef SHELL_SORT_CHECKER_CHECKER_H 
#define SHELL_SORT_CHECKER_CHECKER_H 

#include <iostream>
#include <fstream>

enum verdict { NO = 1, AC, WA, CE, ML, TL, RE, IL, PE, DE };

class Checker{
	public:

		Checker(int count_tests){
			log_file_.open(log_file_path_);
			count_tests_ = count_tests;
		}

		void run_tests(int num_test);
		void run_tests();

		~Checker(){
			log_file_.close();
		}

	private:
		const std::string log_file_path_ = "../../checker/checker_log.txt";
		std::ofstream log_file_;
		std::string data_dir_path_ = "../../test_generator/test_data/";
		int count_tests_;

		enum class log_params_ { NO = 1, VERDICT, MESSAGE, TIME, MEMORY };

	private:
		void write_type(log_params_ param);
		void write_verdict(verdict v);
		void write_message(std::string message);

};
#endif //SHELL_SORT_CHECKER_CHECKER_H 
