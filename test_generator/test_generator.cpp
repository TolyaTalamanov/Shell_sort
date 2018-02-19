#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main(int argc, char* argv[]){
	vector<vector<int>> test_data(7);
	
	test_data[0].resize(10);
	fill(test_data[0].begin(), test_data[0].end(), 5);

	test_data[1].resize(10);
	iota(test_data[1].begin(), test_data[1].end(), 0);

	test_data[2].resize(10);
	iota(test_data[2].rbegin(), test_data[2].rend(), 0);
	
	int seed;
    mt19937 generator(seed);
    uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(),
                                               std::numeric_limits<int>::max());
	test_data[3].resize(10);
    generate(test_data[3].begin(), test_data[3].end(), [&distribution, &generator](){
        return distribution(generator);
    });

	test_data[4].resize(10);
	generate(test_data[4].begin(), test_data[4].end(), [&generator, &distribution](){
				return abs(distribution(generator));
			});

	test_data[5].resize(10);
	generate(test_data[5].begin(), test_data[5].end(), [&generator, &distribution](){
				int random_val = distribution(generator);
				return random_val < 0 ? random_val : -1 * random_val; 
			});
	test_data[6].resize(1);
	
	copy(test_data[0].begin(), test_data[0].end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(test_data[1].begin(), test_data[1].end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(test_data[2].begin(), test_data[2].end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(test_data[3].begin(), test_data[3].end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(test_data[4].begin(), test_data[4].end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(test_data[5].begin(), test_data[5].end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
