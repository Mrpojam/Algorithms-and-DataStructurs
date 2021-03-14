#include<bits/stdc++.h>
using namespace std;

int a[] = {1, 3, 10, 12, 32, 41, 59, 100};

int bs (int value, int L, int R) {
	if (R - L <= 1) return L;
	int mid = (L + R) / 2;
	if (a[mid] == value) return mid;
	if (a[mid] < value)
		return bs(value, mid, R);
	else 
		return bs(value, L, mid+1);
}

int main () {
	int value = 59;
	int n = 8;
	cout << bs(value, 0, n) << endl;
	return 0;
}
