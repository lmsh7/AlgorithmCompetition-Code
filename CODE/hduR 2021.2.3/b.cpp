#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int n;
int num[N];

inline int lowbit(int x) {
	return x & (-x);
}

void add(int x) {
	for(int i = x; i <= n; i += lowbit(i)) {
		num[i] ++;
	}	
}

int query(int x) {
	int w = 0;
	for(int i = x; i > 0; i -= lowbit(i)) {
		w += num[i];
	}
	return w;
}

struct Node {
	int a, b;
	bool operator < (const Node &rhs) const {
		return a < rhs.a;
	}
} c[N];

signed main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		num[0] = 0;
		for(int i = 1; i <= n; ++i) {
			num[i] = 0;
			scanf("%lld %lld", &c[i].a, &c[i].b);
		}
		sort(c + 1, c + n + 1);
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += i - 1 - query(c[i].b);
			add(c[i].b);
		}
		if(ans % 2 == 0) puts("1");
		else puts("-1");
	}
	return 0;
}