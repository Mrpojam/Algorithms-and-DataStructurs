#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

int n, W;
pair<int, int> a[10];

bool comp (pair<int, int> x, pair<int, int> y) {
    return float(x.F/x.S) > float(y.F/y.S);
}

int main () {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        int w, p;
        cin >> w >> p;
        a[i] = {p, w};
    }
    
    sort(a, a + n, comp);

    for (int i = 0; i < n; i++) {
        cout << i << " : " << a[i].F << ' ' << a[i].S << endl;
    }

    int T = 0;
    int i = 0;
    int ans = 0;

    while (true) {
        if (T + a[i].S <= W)
            T += a[i].S, ans += a[i].F;
        else break;
        i++;
    }

    cout << ans << endl;
}