#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int maxN = 1e5+10;
int n, e, indeg[maxN];
bool mark[maxN];
vector<int> adj[maxN], ans;

void topological_sort() {
	queue<int> myq;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			myq.push(i), ans.pb(i);
	while(!myq.empty()) {
		int v = myq.front();
		mark[v] = true;
		myq.pop();
		for (auto u : adj[v]) {
			indeg[u]--;
			if (indeg[u] == 0 && !mark[u])
				ans.pb(u), myq.push(u);
				 
		}
	}
}

int main () {
	cin >> n >> e;
	while(e--) {
		int in, out;
		cin >> out >> in;
		indeg[in]++;
		adj[out].pb(in);
	}
	topological_sort();
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}
