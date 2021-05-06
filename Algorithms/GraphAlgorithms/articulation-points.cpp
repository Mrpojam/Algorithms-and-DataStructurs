#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;

int nodes, edges, low[maxN], parent[maxN], disc[maxN];
bool mark[maxN], AP[maxN];
vector<int> adj[maxN];

void dfs (int v, int time) {
	mark[v] = true;
	int num_child = 0;
	disc[v] = low[v] = ++time;
	for (auto u : adj[v]) 
		if (!mark[u]) {
			num_child ++;
			parent[u] = v;
			dfs (u, time);
			low[v] = min (low[v], low[u]);
			// If V was the root of dfs tree and had atleast 2 children
			if (parent[v] == -1 && num_child >= 2) AP[v] = true;
			// If V was not the root of dfs tree and its subree has a backedge to V's ancestors
			if (parent[v] != -1 && low[u] >= disc[v]) AP[v] = true;
		}
		else if (u != parent[v])
			low[v] = min (low[v], disc[u]);
}

/*
 * disc => discovery time of a vertex
 * parent => parent of a vertex in dfs tree
 * low => the vertex with minimun discovery time that can be reached from subtree rooted with v  
 */

inline void read_graph () {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
		parent[v] = parent[u] = -1;
	}
}

int main () {
	read_graph();
	dfs (1, 0);
	for (int i = 1; i <= nodes; i++)
		if (AP[i])
			cout << i << " Is Cut vertex\n";	
	return 0;
}
