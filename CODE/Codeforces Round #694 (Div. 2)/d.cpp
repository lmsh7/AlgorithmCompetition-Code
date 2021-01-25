#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

int lpf[N];

void pre() {
	for(int i = 2; i <= 1000000; ++i) {
		if(lpf[i] == 0) {
			for(int j = i; j <= 1000000; j += i) {
				if(lpf[j] == 0) {
					lpf[j] = i;
				}
			}
		}
	}
}

int core(int x) {
	int c = 1;
	while(x > 1) {
		int p = lpf[x];
		int e = 1;
		for(x /= p; lpf[x] == p; x /= p) {
			e ^= 1;
		}
		if(e == 1) {
			c *= p;
		}
	}
	return c;
}


int main() {
	pre();
	int t;
	cin >> t;
	while(t--) {
		int n;
		scanf("%d", &n);
		unordered_map <int, int> mp;
		for(int i = 1; i <= n; ++i) {
			int la;
			scanf("%d", &la);
			mp[core(la)]++;
		}
		int max_0 = 0;
		int max_1 = mp[1];
		for (auto i: mp) {
			max_0 = max(max_0, i.second);
			if (i.first > 1 && (i.second & 1) == 0) {
				max_1 += i.second;
			}
		}
		int q;
		scanf("%d", &q);
		while(q--) {
			ll w;
			scanf("%lld", &w);
			if(w == 0) printf("%d\n", max_0);
			else printf("%d\n", max(max_0, max_1));
		}
	}
	return 0;
}