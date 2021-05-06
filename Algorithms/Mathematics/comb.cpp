#include<bits/stdc++.h>
using namespace std;

int n, c[102][102];

void _init_ () {
	for (int i = 0; i <= 100; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
}

int main () {
	_init_ ();
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i+1; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}
}
