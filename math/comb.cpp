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
	while (true) {
		int n, r;
		cin >> n >> r;
		cout << c[n][r] << endl;
	}
}
