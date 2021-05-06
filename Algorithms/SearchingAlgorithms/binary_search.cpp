// Binary Search algorithm by MrPoJ 4th of oct 2020
#include<iostream>
using namespace std;

int Binary_search (int value, int array[], int size) {
	int L = 0, R = size - 1;
 	while (L <= R) {
		int mid = (L + R) / 2;
		if (array[mid] < value)
			L = mid + 1;
		else if (array[mid] > value)
			R = mid - 1;
		else 
			return mid;
	}
	return -1;	
}	

int main() {
	int array[] = {4, 5, 10, 34, 51, 52, 53, 60, 65, 66, 74, 77, 80, 100, 143, 200, 1001};
	cout << Binary_search (143, array, sizeof(array)) << endl;
	return 0;
}
