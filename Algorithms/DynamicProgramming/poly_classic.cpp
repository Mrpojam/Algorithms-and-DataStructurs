#include<bits/stdc++.h>
using namespace std;

/*
	A = a[0] + a[1]x^1 + a[2]x^2 + ...
	B = b[0] + b[1]x^1 + b[2]x^2 + ...
	A * B = c[0] + c[1]x^1 + c[2]x^2 + ...
	c[i + j] = sum of all a[k]*b[u] which i + j == k + u
	T(n) = O(n^2)
*/
vector<double> poly (vector<double> a, vector<double> b) {
	int n = a.size();
	vector<int> c(2*n-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i + j] += a[i]*b[j];
		}
	}
	return c;
}

int main () {
	
	int n;
	vector<double> a, b;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		a.push_back(x);
	} 
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		b.push_back(x);
	} 
	
	vector<double> c = poly(a, b);
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << ' ';
	}
	cout << endl;
	return 0;
}