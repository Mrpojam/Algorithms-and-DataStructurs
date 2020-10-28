#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;

const int maxN = 1e5+10;
int nodes, edges, dsu[maxN];
pair <int, pii> graph[maxN];

struct DSU {
	int parent[maxN], rank[maxN];

	void init () {
		for (int i = 0; i < maxN; i++)
			parent[i] = i;
	}
	int root (int v) {
		if (v == parent[v]) return v;
		return parent[v] = root (parent[v]);
	}
	void union_set (int a, int b) {
		a = root (a);
		b = root (b);
		if (a != b) {
			if (rank[a] < rank[b]) swap (a, b);
			parent[b] = a;
			if (rank[a] == rank[b]) rank[a]++;
		}
	}
};

int kruskal (pair<int, pii> graph[]) {
	int x, y;
	DSU s;
	s.init();
	int cost, minimum = 0;
	for (int i = 0; i < edges; i++) {
		x = graph[i].S.F;
		y = graph[i].S.S;
		cost = graph[i].F;
		if (s.root(x) != s.root(y)) {
			minimum += cost;
			s.union_set(x, y);
		}
	}
	return minimum;
}

void read_graph() {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[i] = {w, {u, v}};
	}
}

int main () {
	read_graph();
	sort(graph, graph + edges);
	cout << kruskal(graph) << endl;
	return 0;
}
