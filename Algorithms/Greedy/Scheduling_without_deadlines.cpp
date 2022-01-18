#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 10;
int t[maxN];

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    sort (t, t + n);

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        sum += t[i];
        ans += sum;
    }
    cout << ans << endl;
}