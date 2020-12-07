#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

struct Mon {
	ll index, x;
	bool operator < (const Mon &rhs) const {
		if (index == rhs.index) {
			return x > rhs.x;
		} else return index < rhs.index;
	}
};


int main() {
	int n;
	cin >> n;
	vector <Mon> p;
	for (int i = 1; i <= n; ++i) {
		Mon la;
		scanf("%lld %lld", &la.index, &la.x);
		p.emplace_back(la);
	}
	sort(p.begin(), p.end());
	ll ans = 0;
	int last = 0;
	ll f_ans = 0;
	for (int q = 0; q < n; ++q) {
		if (q != 0 && (p[q].index != p[q - 1].index)) {
			for (int i = 63; i >= 0; i--) {
				for (int j = last; j <= q - 1; j++) {
					if (p[j].x >= (1 << i) && (p[j].x >> i) & 1) {
						if (((ans >> i) & 1) == 0) {
							ans ^= p[j].x;
						}
						for (int k = last; k <= q - 1; k++) {
							if (p[j].x >= (1 << i) && ((p[k].x >> i) & 1) && k != j) {
								p[k].x ^= p[j].x;
							}
						}
						p[j].x = 0;
						break;
					}
				}
			}
			last = q;
			f_ans = max(f_ans, ans);
			ans = 0;
		} else if (q == n - 1) {
			for (int i = 63; i >= 0; i--) {
				// printf("i = %d ans = %lld\n", i, ans);
				for (int j = last; j <= q; j++) {
					if (p[j].x >= (1 << i) && (p[j].x >> i) & 1) {
						if (((ans >> i) & 1) == 0) {
							ans ^= p[j].x;
						}
						for (int k = last; k <= q; k++) {
							if (p[j].x >= (1 << i) && ((p[k].x >> i) & 1) && k != j) {
								p[k].x ^= p[j].x;
							}
						}
						p[j].x = 0;
						break;
					}
				}
			}
			f_ans = max(f_ans, ans);
		}
	}
	cout << f_ans << endl;

	return 0;
}
/*
4
2 5
2 6
1 5
1 6
*/
