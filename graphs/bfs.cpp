// Breadth First Search algorithm by MrPoJ 5th oct 2020
#include<iostream>
#include<vector>
#include<queue>
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

void bfs(int v) {
	queue<int> q;
	mark[v] = true;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		cout << v << ' ';
		q.pop();
		for (auto u : adj[v]) 
			if (mark[u] == false) 
				q.push(u), mark[u] = true;
	}
}

int main() {
	graph_input();
	bfs(1);
	return 0;
}
