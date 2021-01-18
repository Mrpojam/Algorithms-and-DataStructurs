#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;

int nodes, edges, components, max_comp;
bool mark[maxN];
vector<int> adj[maxN];

int dfs (int v, int cnt) {
	mark[v] = true;
	cnt ++;
	for (auto u : adj[v])
		if (!mark[u])
			return dfs (u, cnt);
	return cnt;
}

inline void read_graph() {
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
	for (int i = 0; i < nodes; i++)
		if (!mark[i]) {
			components ++;
			max_comp = max(dfs(i, 0), max_comp);
		}
	cout << "Number of components : " << components << endl;
	cout << "Max size : " << max_comp << endl;
	return 0;
}
