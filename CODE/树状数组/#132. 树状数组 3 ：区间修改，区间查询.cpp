#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int a[N], b[N], c[N];
int n, q;

int lowbit(int x) {
	return x & (-x);
}

void add_c(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i)) {
		c[i] += y;
	}
}

int getsum_c(int x) {
	int w = 0;
	for (int i = x; i; i -= lowbit(i)) {
		w += c[i];
	}
	return w;
}

void add(int x, int y) {
	for (int i = x; i <= n; i += lowbit(i)) {
		b[i] += y;
	}
}

int getsum(int x) {
	int w = 0;
	for (int i = x; i; i -= lowbit(i)) {
		w += b[i];
	}
	return w;
}

signed main() {
	cin >> n >> q;
	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		add(i, (a[i] - a[i - 1]) * i);
		add_c(i, a[i] - a[i - 1]);
	}

	for (int i = 1; i <= q; ++i) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			add(l, x * l);
			add_c(l, x);
			add(r + 1, (-x) * (r + 1));
			add_c(r + 1, -x);
		} else {
			int l, r;
			cin >> l >> r;
			int sumr =  getsum_c(r) * (r + 1) - getsum(r);
			int suml =  getsum_c(l - 1) * l - getsum(l - 1);
			cout << sumr - suml<< endl;
		}

	}
	return 0;
}