// Depth First Search algorithm by MrPoJ 5th  oct 2020
#include<iostream>
#include<vector>
using namespace std;

const int maxN = 1e5+10;

int nodes, edges;
bool mark[maxN];
vector<int> adj[maxN];

void graph_input() {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
}

void dfs(int v) {
	mark[v] = true;
	cout << v << ' ';
	for (auto u : adj[v])
		if (mark[u] == false)
			dfs (u);
}

int main() {
	graph_input();
	dfs(1);
	return 0;
}
