#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3+10;
int n, wt, weight[maxN], value[maxN];
int dp[maxN][maxN];

int knapsack() {
	for (int i = 1; i <= n; i++)
		for (int k = 0; k <= wt; k++)
			if (weight[i] <= k)
				dp[i][k] = max (dp[i-1][k], dp[i-1][k-weight[i]] + value[i]);
			else
				dp[i][k] = dp[i-1][k];
	return dp[n][wt];
}

void input() {
	cin >> n >> wt;
	for (int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];
}

int main () {
	input();
	cout << knapsack() << endl;
	return 0;
}
