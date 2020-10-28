#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10, k = 17;
int n, arr[maxN], sp[maxN][k];

void _init_ () {
	for (int i = 0; i < n; i++)
		sp[i][0] = arr[i];
	for (int j = 1; (1<<j) <= k; j++)
		for (int i = 0; i + (1<<j) <= n; i++)
			sp[i][j] = sp[i][j-1] + sp[i + (1<<(j-1))][j-1];
}

int query (int l, int r) {
	int ret = 0;
	for (int j = k; j >= 0; j--) 
		if (l + (1<<j) - 1 <= r) {
			ret += sp[l][j];
			l += 1<<j;
		}
	return ret;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	_init_();
	while (true) {
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}
