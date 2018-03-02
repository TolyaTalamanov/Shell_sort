#include "file_manager.h"

void FileManager::write(std::vector<int> data){ 
	file_.open(file_path_, ios::binary);

	ostream_iterator<int> file_iterator(file_, " ");

	copy(data.begin(), data.end(), file_iterator);
}

std::vector<int> load(){
	file_.open(file_path_, ios::in | ios::binary);

    std::vector<int> data;

	istream_iterator<int> begin_file(file_);
	istream_iterator<int> end_file;

	copy(begin_file, end_file, back_inserter(data));

	file_.close();

    return data;
}
