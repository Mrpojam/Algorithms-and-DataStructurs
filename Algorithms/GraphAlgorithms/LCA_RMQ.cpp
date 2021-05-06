#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
int n, height[maxN], first[maxN], root;
vector<int> adj[maxN];
vector<pair<int, int>> euler;

void dfs (int v, int p, int h) {
	height[v] = h;
	euler.push_back({h,v});
	first[v] = euler.size();
	for (auto u : adj[v])
		if (u != p) {
			dfs(u, v, h+1);
			euler.push_back({h,v});
		}
}

int lg[20];//, sp[maxN][20];
pair<int, int> sp[maxN][20];
pair<int, int> get (pair<int,int> x, pair<int, int> y) {
	return x.first < y.first ? x : y;
}

void spars () {
	lg[0] = 1;
	int N = euler.size();
	for (int i = 2; i <= N; i++)
		lg[i] = lg[i/2] + 1;
	for (int i = 0; i < N; i++)
		sp[i][0] = euler[i];
	for (int j = 1; (1<<j) <= 17; j++)
		for (int i = 0; i + (1<<j) <= N; i++)
			sp[i][j] = get (sp[i][j-1], sp[i + (1<<(j-1))][j-1]);	
}

int query (int v, int u) {
	int l = first[u], r = first[v];
	if (l > r) swap (l, r);
	int j = lg[r-l+1];
	return get (sp[l][j], sp[r-(1<<j)][j-1]).second;
}

inline void _input() {
	cin >> n >> root;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main () {
	_input();
	dfs(root, 0, 1);
	spars();
/*	for (int i = 0; i < euler.size(); i++)  {
		cout << euler[i] << ' ' << height[euler[i]] << endl;
	}*/
	while (true) {
		int v, u;
		cin >> v >> u;
		cout << query(v, u) << endl;
	}
}
