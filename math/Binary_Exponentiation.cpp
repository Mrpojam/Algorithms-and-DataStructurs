#include<bits/stdc++.h>
using namespace std;

int p(int n, int t) {
	long long result = 1;
	while (t > 0) {
		if (t & 1) result *= n;
		n *= n;
		t >>= 1;
	}
	return result;
}

int main () {
	int n, t;
	cin >> n >> t;
	cout << p(n, t) << endl;
}