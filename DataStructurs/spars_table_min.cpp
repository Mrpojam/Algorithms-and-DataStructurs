#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10, k = 17;
int n, arr[maxN], sp[maxN][k], lg[maxN];

void _init_ () {
	lg[1] = 0;
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i/2] + 1;
        for (int i = 0; i < n; i++)
                sp[i][0] = arr[i];
        for (int j = 1; (1<<j) <= k; j++)
                for (int i = 0; i + (1<<j) <= n; i++)
                        sp[i][j] = min(sp[i][j-1], sp[i + (1<<(j-1))][j-1]);
}

int main () {
        cin >> n;
        for (int i = 0; i < n; i++)
                cin >> arr[i];
        _init_();
        while (true) {
                int l, r;
                cin >> l >> r;
		int j = lg[r-l+1];
                cout <<  min(sp[l][j], sp[r - (1<<j)][j-1]) << endl;
        }
}  
