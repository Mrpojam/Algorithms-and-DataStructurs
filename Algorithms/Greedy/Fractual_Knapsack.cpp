#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

bool compair(pair<int, int> x, pair<int, int> y) {
    double r1 = (double)x.S / (double)x.F;
    double r2 = (double)y.S / (double)y.F;
    return r1 > r2;
}

double KnapSack(int T, pair<int, int> rocks[], int n) {
    sort(rocks, rocks + n, compair);
    int W = 0;
    double ans = 0.0; 
    for (int i = 0; i < n; i++) {
        if (W + rocks[i].F <= T) {
            W += rocks[i].F;
            ans += rocks[i].S;
        }
        else {
            int rem = T - W;
            ans += rocks[i].S
                          * ((double)rem / (double)rocks[i].F);
            break;
        }
    }
    return ans;
}

int main() {
    int T, n;
    cin >> n >> T; 
    pair<int, int> rocks[n+1];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        rocks[i].F = x;
        rocks[i].S = y;
    }
    cout << KnapSack(T, rocks, n) << endl;
    return 0;
}