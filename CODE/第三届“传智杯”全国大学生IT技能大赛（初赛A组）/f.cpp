#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;

ll fa[N];
ll a[N];

ll find_fa(ll x) {
	return x == fa[x] ? x : fa[x] = find_fa(fa[x]);
}

ll lowbit(ll x) {
	return x & (-x);
}

struct Edge{
	ll to,from;
};


int main() {
	long long  n, c1, c2;
	cin >> n >> c1 >> c2;
	for(int i = 1; i <= n; ++i) fa[i] = i;
 	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		for(int j = 1; j < i; ++j) {
			int la = a[i] ^ a[j];
			if((la & lowbit(la)) == la) {
				if(c1 <= c2) {
					ll faa = find_fa(i);
					ll fbb = find_fa(j);
					if(faa != fbb) {
						ans += c1;
						fa[fa[fbb]] = fa[fa[faa]];
					}
				}
			} else {
				if(c1 >= c2) {
					ll faa = find_fa(i);
					ll fbb = find_fa(j);
					if(faa != fbb) {
						ans += c2;
						fa[fa[fbb]] = fa[fa[faa]];
					}
				}				
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			int la = a[i] ^ a[j];
			if((la & lowbit(la)) == la) {
				if(c1 >= c2) {
					ll faa = find_fa(i);
					ll fbb = find_fa(j);
					if(faa != fbb) {
						ans += c1;
						fa[fa[fbb]] = fa[faa];
					}
				}
			} else {
				if(c1 <= c2) {
					ll faa = find_fa(i);
					ll fbb = find_fa(j);
					if(faa != fbb) {
						ans += c2;
						fa[fa[fbb]] = fa[faa];
					}
				}				
			}
		}
	}
	cout << ans <<endl;
	return 0;
}
/*
3
1 9
8 2 1
*/