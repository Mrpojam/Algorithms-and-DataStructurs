// Insertion Sort algorithm by MrPoJ 5th oct 2020
#include<iostream>
using namespace std;

int n, array[1000];
void _input();

void insertion_sort () {
	for (int i = 2; i <= n; i++) {
		int key = array[i];
		int j = i-1;
		while (j > 0 && array[j] > key)
			array[j+1] = array[j], j--;
		array[j+1] = key;
	}
}

int main () {
	_input();
	insertion_sort();
	for (int i = 1; i <= n; i++)
		cout << array[i] << ' ';
	return 0;
}

void _input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> array[i];
}
