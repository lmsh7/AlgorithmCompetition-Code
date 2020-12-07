#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


const ll P = 1000000007;
const int N = 1e5 + 10;
const ull haozi = 307751774483;
const ull weizhi = 82018674586368;

int n;
string s;
ull bin[N];
ull hsh[N];

void prev() {
    bin[0] = 1;
    for (int i = 1; i <= n; ++i) bin[i] = bin[i-1] * 233;
    for (int i = 0; i < n; ++i) hsh[i] = hsh[i-1] * 233 + s[i];
}

unsigned long long gethsh(int l, int r) {
    return hsh[r] - (l ? hsh[l-1] : 0) * bin[r-l+1];
}

int main() {
	cin >> n >> s;
	prev();
	ll ansA = 0;
	ll ansB = 0;
	for(int i = 4; i < n; ++i) {
		if(gethsh(i - 4, i) == haozi) ansA ++;
	}
	for(int i = 5; i < n; ++i) {
		if(gethsh(i - 5, i) == weizhi) ansB ++;
	}
	cout << (ansA % P * ansB % P) % P;
	return 0;
}
/*
307751774483
*/