#include<bits/stdc++.h>
using namespace std;

double* poly (double *a, double *b, int n) {
	
	cout << n << endl;

	if (n == 1) {
		double c[] = {a[0] * b[0]};
		return c;
	}

	int d = n/2;

	double  aHigh[d];
    double  bHigh[d];       
    double  aLow[d-n%2];
    double  bLow[d-n%2];
 for (int i = 0; i < d; i++){
        aHigh[i] = a[i+d];
        bHigh[i] = b[i+d];
    
        aLow[i] = a[i];
        bLow[i] = b[i];
    }

    double  *lowAB = poly(aLow,bLow,d);  
    double  *lowAHighB = poly(aLow,bHigh,d);
    double  *lowBHighA = poly(aHigh,bLow,d);
    double  *highAB = poly(aHigh,bHigh,d);
    double  ab[(2 * n)-1];        
    
    for (int i = 0; i < n-1; i++){
        ab[i] += lowAB[i];
       ab[i+d] += lowAHighB[i] + lowBHighA[i];
        ab[i+(2*d)] += highAB[i];
    }        
    return ab;
}

int main () {
	
	int n;
	cin >> n;

	double a[n], b[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	double *c = poly(a, b, n);
	for (int i = 0; i < 3; i++) {
		cout << c[i] << ' ';
	}
	cout << endl;
	return 0;
}