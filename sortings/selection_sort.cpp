// Selection Sort algorithm by MrPoJ 5th oct 2020
#include<bits/stdc++.h>
using namespace std;

int n, array[1000];
void _input();

void selection_sort () {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++)
			if (array[j] < array[min])
				min = j;
		swap (array[min], array[i]);
		
	}
}

int main () {
	_input();
	selection_sort();
	for (int i = 0; i < n; i++)
		cout << array[i] << ' ';
	return 0;
}

void _input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> array[i];
}
