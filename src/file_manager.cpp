#include "file_manager.h"

void FileManager::write(std::vector<int> data){ 
	file_.open(file_path_, ios::binary);

	ostream_iterator<int> file_iterator(file_, " ");

	copy(data.begin(), data.end(), file_iterator);
}
