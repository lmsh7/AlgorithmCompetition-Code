#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1e6 + 10;

typedef long long ll;

ll a[Maxn], ans[Maxn << 2], tag[Maxn << 2];

inline ll ls(ll x) {
	return x << 1;
}

inline ll rs(ll x) {
	return x << 1 | 1;
}


inline void f(ll p, ll l, ll r, ll k) {
	tag[p] = tag[p] + k;
	ans[p] = ans[p] + 1LL * k * (r - l + 1);;
}

inline void push_up(ll p) {
	ans[p] = ans[ls(p)] + ans[rs(p)];
}

inline void push_down(ll p, ll l, ll r) {
	ll mid = l + ( (r - l) >> 1 );
	f(ls(p), l, mid, tag[p]);
	f(rs(p), mid + 1, r, tag[p]);
	tag[p] = 0;
}

void build(ll p, ll l, ll r) {
	if (l == r) {
		ans[p] = a[l];
	} else {
		ll mid = l + ( (r - l) >> 1 );
		build(ls(p), l, mid);
		build(rs(p), mid + 1, r);
		push_up(p);
	}
}

void update(ll nl, ll nr, ll l, ll r, ll p, ll k) {
	if (nl <= l && nr >= r) {
		ans[p] += 1LL * (r - l + 1) * k;
		tag[p] += k;		//如果更新区间被节点区间完全包含, 则更新节点的值,打懒标记
	} else {	//如果不是就拆分查找
		push_down(p, l, r);//传递懒标记, 如果不传递, push_up上来的就是假的
		ll mid = l + ( (r - l) >> 1 );
		if (nl <= mid) update(nl, nr, l, mid, ls(p), k);
		if (nr > mid) update(nl, nr, mid + 1, r, rs(p), k);
		push_up(p);
	}
}

ll query (ll nl, ll nr, ll l, ll r, ll p) {
	if(nl <= l && nr >= r) {
		return ans[p];
	} else {
		push_down(p, l, r);
		ll res = 0;
		ll mid = l + ( (r - l) >> 1 );
		if(nl <= mid) res += query(nl, nr, l, mid, ls(p));
		if(nr > mid) res += query(nl, nr, mid + 1, r, rs(p));
		return res;
	}
	//如果查询区间被节点区间完全包含, 则输出这个值
	//如果不是就拆分查找
	//传递懒标记
}
int main() {
	// freopen("1.in", "r", stdin);
	ll n, q, opt, la, lb, lc;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	build(1, 1, n);
	while (q--) {
		scanf("%lld", &opt);
		switch (opt) {
		case 1: {
			scanf("%lld %lld %lld", &la, &lb, &lc);
			update(la, lb, 1, n, 1, lc);
			break;
		}
		case 2: {
			scanf("%lld %lld", &la, &lb);
			cout << query(la, lb, 1, n, 1) <<endl;
			break;
		}
		}
	}
}