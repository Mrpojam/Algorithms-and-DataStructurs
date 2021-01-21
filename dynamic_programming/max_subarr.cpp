#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n, a[maxN];

int cross_sum (int left, int right) {
	int mid = (left + right) / 2;
	int sum = 0, left_sum = INT_MIN;
	for (int i = mid; i >= left; i--) {
		sum += a[i];
		left_sum = max(sum, left_sum);
	}
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = mid+1; i <= right; i++) {
		sum += a[i];
		right_sum = max (sum, right_sum);
	}
	return left_sum+right_sum;
}

int solve (int left, int right) {
	if (left == right)
		return a[left];
	int mid = (left + right) / 2;
	int left_answer = solve (left, mid);
	int right_answer = solve (mid+1, right);
	int cross_answer = cross_sum (left, right);
	return max (max(left_answer, right_answer), cross_answer);
}

int main () {
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << solve (0, n-1) << endl;

	return 0;
}
