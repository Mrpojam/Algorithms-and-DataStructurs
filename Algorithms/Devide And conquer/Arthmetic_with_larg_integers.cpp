#include<bits/stdc++.h>
using namespace std;

#define ll long long

long long p[18];

int int_size (ll x) {
    int ret = 0;
    while (x) {
        x/=10;
        ret++;
    }
    return ret;
}

ll prod (ll u, ll v) {
    ll x, y, w, z;
    int n, m;
    n = max(int_size(u), int_size(v));

    if (u == 0 || v == 0) 
        return 0;
    
    else if (n <= 2) 
        return u * v;
    
    else {
        /*
            u = 120
            v = 80001
            => u *v = 9600120
            n = 5
            m = 2

            x = 800
            y = 1

            w = 1
            z 20

            u*v = (x*w) * 10^4 + ((x*z) + (w*y)) * 10^2 + y*z
            8000000 + ((16000) + 1) * 100 + 20 = 9600120
        */
        m = n/2;
        x = u / p[m];
        y = u % p[m];
        w = v / p[m];
        z = v % p[m];
        return prod(x, w) * p[2 * m] + (prod(x, z) + prod(w, y)) * p[m] + prod(y, z);
    }

}

int main () {
    p[0] = 1;
    for (int i = 1; i <= 18; i++)
        p[i] = p[i-1]*10;
    cout << prod(80001, 120) << endl;
    return 0;
}