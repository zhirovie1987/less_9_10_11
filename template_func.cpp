#include <iostream>

using namespace std;
template <typename T>

void Swap (T &x, T &y) {
	auto Temp = x;
	x = y;
	y = Temp;
}
template <typename T>
void bsort (T *begin, T *end) {
	size_t arr_size = end - begin;
	cout<<arr_size<<endl;
	for (auto j = 0; j < arr_size; ++j) {
		for (auto i = 1; i < arr_size - j; ++i) {
			if (*(begin + i) < *(begin + i - 1)) {
				Swap (*(begin + i), *(begin + i - 1));
			}
		}
	}
}

int main () {
	
	double Array_To_Sort[] = {6, 7, -1, 4, 5, 0, 6, 123.9, 0, 9, 1, 33, 8, -9, 6, 7, -2, 4, 5, 0, -90.1, 9, 1, 3, 8, -9};
	char char_arr[] = "Hello_1239_World!";
		for (auto  y : Array_To_Sort) cout << y << ' ';
	bsort (begin(Array_To_Sort), end(Array_To_Sort));
		for (auto  y : Array_To_Sort) cout << y << ' ';
	return 0;
}
