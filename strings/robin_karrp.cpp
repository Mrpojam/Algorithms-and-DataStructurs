#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;
const int mod = 1e9+9, p = 31;
long long pw[maxN];
long long str_hash[maxN], patt_hash;

void power_init () {
	pw[0] = 1;
	for (int i = 1; i <= maxN; i++)
		pw[i] = (pw[i-1] * p) % mod;
}

void compute_hash (string _string, string _pattern) {
	for (int i = 0; i < _string.size(); i++)
		str_hash[i+1] = (str_hash[i] + (_string[i] - 'a' + 1) * pw[i]) % mod;
	for (int i = 0; i < _pattern.size(); i++) 
		patt_hash = (patt_hash + (_pattern[i] - 'a' + 1) * pw[i]) % mod;
}

vector<int> robin_karp (string _string, string _pattern) {
	compute_hash (_string, _pattern);
	vector<int> answer;
	int S = _string.size(), P = _pattern.size();
	for (int i = 0; i + P < S; i++) {
		long long current_hash = (str_hash[i+P] + mod - str_hash[i]) % mod;
		if (current_hash == (patt_hash * pw[i]) % mod)
			answer.push_back(i);
	}
	return answer;
}

int main () {
	power_init();
	while (true) {
		memset(str_hash, 0, maxN);
		patt_hash = 0;
		string _string, _pattern;
		cin >> _string >> _pattern;
		vector<int> answer = robin_karp(_string, _pattern);
		for (auto index : answer)
			cout << index << ' ';
		cout << endl;
	}
	return 0;
}
