struct DSU {
	int parent[max_size];
	int rank[max_size];
	int find_root (int v) {
		if (v == parent[v]) return v;
		return parent[v] = find_root(parent[v]);
	}
	void set (int v) {
		parent[v] = v;
		rank[v] = 0;
	}
	void union_set (int a, int b) {
		a = find_root(a);
		b = find_root(b);
		if (a != b)
			if (rank[a] < rank[b]) swap (a, b);
		parent[b] = a;
		if (rank[a] == rank[b]) rank[a]++;
	}
};
