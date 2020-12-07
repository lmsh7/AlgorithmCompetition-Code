#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50000 + 5;
const int M = 100000 + 10;

int n, m, ecnt;
int head[N], vis[N];
ll sum[N];
ll p[70];

struct Edge {
	int to, next;
	ll val;
} e[M << 1];
	
inline void adde (int x, int y, ll z) {
	e[++ecnt].to = y;
	e[ecnt].val = z;
	e[ecnt].next = head[x];
	head[x] = ecnt;
	return;
}

void insert(ll x) {
	for(int i = 61; i >= 0; i--) {
		if((x & (1LL << i)) == (1LL << i)) {
			if(p[i] == 0) {
				p[i] = x;
				break;
			} 
			x ^= p[i];	
		}
	}	
}

ll query(ll x) {
	ll ans = x;
	for(int i = 61; i >= 0; i --) {
		if((ans ^ p[i]) > ans) {
			ans ^= p[i];
		}
	}
	return ans;
}

void dfs(int x, ll res) {
	vis[x] = 1;
	sum[x] = res;
	for (int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if (!vis[v]) {
			dfs(v, res ^ e[i].val);
			
		} else {
			insert(res ^ sum[v] ^ e[i].val);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1, la, lb; i <= m; ++i) {
		ll lc;
		cin >> la >> lb >> lc;
		adde(la, lb, lc);
		adde(lb, la, lc);
	}
	dfs(1, 0);
	// insert();
	cout << query(sum[n]);
	return 0;
}