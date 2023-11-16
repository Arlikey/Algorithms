#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

int random() {
	return rand() % 10;
}

int main() {
	srand(time(0));

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	ostream_iterator<int> out(cout, " ");

	cout << "Static array: ";
	copy(arr, arr + 10, out);

	list<int> lst(10, 0);
	generate(lst.begin(), lst.end(), random);

	//copy(arr, arr + 10, lst.begin());

	cout << "\nList by random generate: ";
	copy(lst.begin(), lst.end(), out);

	list<int> secondLst;
	insert_iterator<list<int>> it(secondLst, secondLst.begin());
	copy(arr, arr + 10, it);

	cout << "\nList by insert_iterator: ";
	copy(secondLst.begin(), secondLst.end(), out);

	return 0;
}