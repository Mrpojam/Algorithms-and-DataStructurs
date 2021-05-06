#include<bits/stdc++.h>
using namespace std;

int main () {
	int a, b, c;
	// ax + by = c
	int d, e, f;
	// dx + ey + f
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	
	int y = (f*a - d*c) / (e*a - d*b);
	int x = (c - b*y) / a;

	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;

	return 0;
}
