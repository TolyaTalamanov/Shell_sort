#ifndef SHELL_SORT_INCLUDE_FILE_MANAGER_H
#define SHELL_SORT_INCLUDE_FILE_MANAGER_H

#include <fstream>
#include <iterator>
#include <vector>
#include <string>

class FileManager{
    public:
        FileManager(const string file_path){
            file_path_ = file_path;
        }
        std::vector<int> load();
        void write(std::vector<int> data);
    private:
        std::string file_path_;
        std::ofstream file_;
}
#endif //SHELL_SORT_INCLUDE_FILE_MANAGER_H
