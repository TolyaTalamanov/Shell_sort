#ifndef SHELL_SORT_CHECKER_CHECKER_H 
#define SHELL_SORT_CHECKER_CHECKER_H 

#include <iostream>
#include <fstream>

enum verdict { NO = 1, AC, WA, CE, ML, TL, RE, IL, PE, DE };

class Checker{
	private:
		std::ofstream log_file_;
		const std::string log_file_path_ = "../../shell_sort/checker/cheker_log_log.txt";

		enum class log_params_ { NO = 1, VERDICT, MESSAGE, TIME, MEMORY };

	private:
		void write_type(log_params_ param){
			log_file_ << static_cast<int>(param) << std::endl;
		}

	public:

		Checker(){
			log_file_.open(log_file_path_);
		}

		~Checker(){
			log_file_.close();
		}

		void write_verdict(verdict v){
			write_type(log_params_::VERDICT);
			log_file_ << v;
		}

		void write_message(std::string message){
			write_type(log_params_::MESSAGE);
			log_file_ << message;
		}
};
#endif //SHELL_SORT_CHECKER_CHECKER_H 
