// Merge Sort algorithm by MrPoJ 10th oct 2020
#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+11;
int n, a[maxN],cnt;

void merge (int l, int r) {
        int mid = l + r >> 1;
        int p1 = l, p2 = mid+1, k = 0;
        int arr[n] = {};
        for (int i = l; i <= r; i++)
                if (p1 > mid)
                        arr[k++] = a[p2++];
                else if (p2 > r)
                        arr[k++] = a[p1++];
                else if (a[p1] < a[p2])
                        arr[k++] = a[p1++];
                else
                        arr[k++] = a[p2++];
        for (int i = 0; i < k; i++)
                a[l++] = arr[i];

}



void _sort (int l = 0, int r = n-1) {
	int mid = l + r >> 1;
	if (l < r) 
		_sort(l, mid), _sort (mid+1, r);
	 merge (l, r);
	 cout << cnt++ << ": ";
	 for (int i = 0; i < n; i++) cout << a[i] << ' ';
	 cout << endl;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	_sort ();
	return 0;
}
