struct Segment_tree {
	int tree[400005];

	void build (int arr[], int id, int st, int en) {
		if (st == en) 
			tree[id] = arr[st];
		else {
			int mid = (st+en)/2;
			build (arr, id*2, st, mid);
			build(arr, id*2+1, mid+1, en);
			tree[id] = tree[id*2] + tree[id*2+1];
		}
	}

	void update (int pos, int value, int id, int st, int en) {
		if (st == en) 
			tree[id] += value;
		else {
			int mid = (st+en)/2;
			if (st <= pos && pos <= mid)
				update (pos, value, id*2, st, mid);
			else
				update (pos, value, id*2+1, mid+1, en);
			tree[id] = tree[id*2] + tree[id*2+1];
		}
	}

	int sum (int l, int r, int id, int st, int en) {
		if (r < st || en < l) return 0;
		if(l <= st && en <= r) return tree[id];
		int mid = (st+en)/2;
		return sum (l, r, id*2, st, mid) + sum (l, r, id*2+1, mid+1, en);
	}
};



