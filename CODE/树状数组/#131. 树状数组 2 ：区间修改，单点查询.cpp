#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, q;

int a[N];
ll b[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i)) {
		b[i] += y;
	}
}

ll getsum(int x) {
	ll w = 0;
	for(int i = x; i; i -= lowbit(i)) {
		w += b[i];
	}
	return w;
}

int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		add(i, a[i] - a[i - 1]);
	}
	for(int i = 1; i <= q; ++i) {
		int opt;
		cin >> opt;
		if(opt == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			add(l, x);
			add(r + 1, -x);
		} else {
			int x;
			cin >> x;
			cout << getsum(x) <<endl;
		}
	}
	return 0;
}