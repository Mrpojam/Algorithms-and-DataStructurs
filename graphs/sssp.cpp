// single source shortest path (in DAG)
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
int nodes, edges, dist[maxN], indeg[maxN];
bool mark[maxN];
vector<pair<int, int>> adj[maxN];

void topol_sort (int v) {
	if (indeg[v] != 0) return;
	dist[0] = 0;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		mark[u] = true;
		q.pop();
		for (auto k : adj[u]) {
			indeg[k.first] --;
			dist[k.first] = min (dist[k.first], dist[u] + k.second);
			if (indeg[k.first] == 0 && !mark[k.first])
				q.push(k.first);
		}
	}
}

inline void read_graph() {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		indeg[v]++;
		adj[u].push_back({v, w});
	}
}

int main () {
	read_graph();
	for (int i = 0; i < nodes; i++)
		dist[i] = 100000009;
	topol_sort(0);
	for (int i = 0; i < nodes; i++)
		cout << i+1 << " : " << dist[i] << endl;
	return 0;
}
