#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e2+10;

int dist[maxN][maxN];
int nodes, edges;

void floyd () {
	for (int k = 0; k < nodes; k++)
		for (int i = 0; i < nodes; i++)
			for (int j = 0; j < nodes; j++)
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
}

inline void read_graph () {
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;
		dist[--u][--v] = weight;
		dist[v][u] = weight;
	}
}

int main () {
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++)
			dist[i][j] = 10000009;
	read_graph();
	floyd();
	for (int i = 0; i < nodes; i++)
		for (int j = i+1; j < nodes; j++)
			cout << i+1 << ' ' << j+1 << ' ' << dist[i][j] << endl;	
	return 0;
}
