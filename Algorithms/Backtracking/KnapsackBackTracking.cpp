#include<bits/stdc++.h>
using namespace std;

int n, W, v[5], w[5], a[5];
int maxvalue = 0;

void checkmax () {
    int weight = 0;
    int value = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            weight += w[i];
            value += v[i];
        }
    }
    if (weight <= W && maxvalue <= value) {
        maxvalue = value;
        cout << "a new max value has been found : " << maxvalue << endl;
        cout << "combination : ";
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
}

void knapsack (int i) {
    if (i >= n) {
        checkmax();
    }
    else {
        a[i] = 0;
        knapsack(i+1);
        a[i] = 1;
        knapsack(i+1);
    }
}

int main () {
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    knapsack(0);
}