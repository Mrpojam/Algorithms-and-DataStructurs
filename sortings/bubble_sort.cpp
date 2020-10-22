// Bubble Sort algorithm bu MrPoJ 4th of oct 2020
#include<iostream>
using namespace std;

const int maxN = 1e5+10;
int n, array[maxN];

void Bubble_sort() {
	int tmp = 0;
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n-i-1; j++)
			if (array[j] > array[j+1])
				tmp = array[j+1], array[j+1] = array[j], array[j] = tmp;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> array[i];
}

int main () {
	input();
	Bubble_sort();
	for (int i = 0; i < n; i++)
		cout << array[i] << ' ';
	return 0;
}
