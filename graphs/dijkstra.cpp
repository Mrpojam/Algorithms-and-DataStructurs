#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second

const int maxN = 1e5+10;
const int inf = INT_MAX;
int n, e, dist[maxN];
vector<pii> adj[maxN];
set<pii> s;
	
void read_graph() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[i] = inf;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
}

void update (pii node, pii u) {
	if (dist[node.F] > dist[u.S] + node.S) {
		dist[node.F] = dist[u.S] + node.S;
		s.insert({dist[node.F], node.F});
	}
}

void dijkstra (int v) {
	dist[v] = 0;
	s.insert({0, v});
	while (!s.empty()) {
		pii u = *s.begin();
		s.erase(s.begin());
		for (auto node : adj[u.S]) 
			update(node, u);
		
	}
}

int main() {
	read_graph();
	int v;
	cin >> v;
	dijkstra(v);
	for (int i = 1; i <= n; i++)
		cout << i << ": " << dist[i] << endl;
	return 0;
}