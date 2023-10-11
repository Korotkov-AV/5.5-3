// 5.5-3.cpp 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class functor {
private:
	int sum;
	int count;

public:
	functor() {
		sum = 0, count = 0;
	}

	void operator()(int i) {
		if (i % 3 == 0) {
			sum += i;
			count++;
		}
	}

	int get_sum() {
		return sum;
	}

	int get_count() {
		return count;
	}
};

int main() {
	vector<int> vec{ 1, 3, 6, 4, 2, 6, 8 };
	functor count_and_sum;

	int s = for_each(vec.begin(), vec.end(), count_and_sum).get_sum();
	int c = for_each(vec.begin(), vec.end(), count_and_sum).get_count();

	for (auto n : vec) {
		cout << n << " ";
	}

	cout << "\nsum " << s;
	cout << "\ncount " << c;
}