/*
* @Author: LMSH7
* @Date:   2021-01-11 20:21:05
* @Last Modified by:   LMSH7
* @Last Modified time: 2021-01-11 21:08:35
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, q;
ll a[N], c[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i)) {
		c[i] += y;
	}
}

ll getsum(int x) {
	ll w = 0;
	for(int i = x; i; i -= lowbit(i)) {
		w += c[i];
	}
	return w;
}

int main() {

	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		add(i, a[i]);
	}
	for(int i = 1; i <= q; ++i) {
		int opt;
		cin >> opt;
		if(opt == 2) {
			int l, r;
			cin >> l >> r;
			cout << getsum(r) - getsum(l - 1) <<endl;
		} else {
			int la, lb;
			cin >> la >> lb;
			add(la, lb);	
		}
	}
	return 0;
}