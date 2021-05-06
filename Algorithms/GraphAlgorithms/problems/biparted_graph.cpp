#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;

int nodes, edges, color[maxN], cnt;
bool mark[maxN], biparted = true;
vector<int> adj[maxN];

void dfs (int v, bool c) {
	mark[v] = true;
	color[v] = c;
	for (auto u : adj[v])
		if (!mark[u])
			dfs (u, 1^c);
		else if (color[v] == color[u])
			biparted = false;
}

inline void read_graph () {
	cin >> nodes >> edges; 
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adj[--v].push_back(--u);
		adj[u].push_back(v);
	}
}

int main () {
	read_graph();
	dfs (0, 0);
	cout << (biparted ? "Biparted" : "Not Biparted") << endl;
	return 0;
}
