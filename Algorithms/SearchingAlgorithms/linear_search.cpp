// Linear Search algorithm by MrPoJ 4th of october 2020
#include<iostream>
using namespace std;

int Linear_Search (int value, int sizeof_array, int array[]) {
	for (int i = 0; i < sizeof_array; i++)
		if (value == array[i]) 
			return i;
	return -1;
}

int main() {
	int array[] = {1, 23, 45, 3, 2, 10, 5, 101};
	cout << Linear_Search (3, sizeof(array), array) << endl;	
	return 0;
}
