/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/**
*	Template function for performing the recursive binary search
*/
template <typename T>
int binary_search(const vector<T> &items, int first, int last, T target) {
	//// FIXME: Implement recursive binary search
	if (first > last) //unsuccessful search, not in order
		return -1;
	else {
		int middleNum = (first + last) / 2; //middle num

		if (target == items[middleNum]) {//the middle num equals the desired search num, if statement ends the function
			return middleNum;
		}
		 
		if (target < items[middleNum]) { //if the target is less than the middle num in the array, 
									//then call the function to search for the middle num in the lower half and continue to use recursion until the num is found or not found 
			return binary_search(items, first, middleNum - 1, target);
		}
		else {
			return binary_search(items, middleNum + 1, last, target);
		}

	}
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binary_search(const vector<T> &items, T target) {
	return binary_search(items, 0, items.size() - 1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);
	for (int j = 0; j < 100; j += 10) { //table of 100 values
		
		for (int i = 0; i < 10; ++i) {// initialize the vector with random values , column length
			haystack.push_back(rand() % 100 +1);
			std::cout << haystack.at(i + j)<< "	"; //to see numbers that are being put into the vector
		}
		cout << endl; //cout after 10 items 
	}

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		}
		else {
			int idx = binary_search(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}