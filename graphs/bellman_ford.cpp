#include<bits/stdc++.h>

#define F first
#define S second

using namespace std;

const int maxN = 1e3+10;

int nodes, edges;
int dist[maxN], weight[maxN];
vector<pair<pair<int, int>, int>> edge; // {{u, v}, weight}

inline void bellman_ford (int source) {
	memset(dist, 1, sizeof(dist));
	dist[source] = 0;
	for (int i = 0; i < nodes - 1; i++)
		for (auto e : edge) 
		       if (dist[e.F.F] + e.S < dist[e.F.S])
				dist[e.F.S] = dist[e.F.F] + e.S;
}

inline void read_graph() {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v, weight;
		cin >>  u >> v >> weight;
		edge.push_back({{--u, --v}, weight});
	}
}

int main () {
	read_graph();
	int source;
	cin >> source;
	bellman_ford(--source);
	for (int i = 0; i < nodes; i++)
		cout << i+1 << " : " << dist[i] << endl;
	return 0;
}
