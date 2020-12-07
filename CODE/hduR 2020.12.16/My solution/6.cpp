#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, m;
int ecnt, dfs_clock, col_cnt, top;
int low[N], dfn[N], col[N], sta[N], ins[N];
int head[N];

struct Edge {
	int to, next, h;
} e[M];

inline void adde(int x, int y, int z) {
	e[++ecnt].to = y;
	e[ecnt].h = z;
	e[ecnt].next = head[x];
	head[x] = ecnt;
}

bool tarjan(int x, int val) {
	dfn[x] = ++dfs_clock;
	ins[x] = 1;
	low[x] = dfn[x];
	for(int i = head[x]; i; i = e[i].next) {
		if(e[i].h <= val) continue;
		int v = e[i].to;
		if(dfn[v]) {
			if(ins[v])
				low[x] = min(low[x], low[v]);
		} else {
			if(!tarjan(v, val)) return false;
			low[x] = min(low[x], low[v]);
		}
	}
	if(low[x] != dfn[x]) return false;
	ins[x] = 0;
	return true;
}

bool check(int x) {
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(col, 0, sizeof(col));
	memset(ins, 0, sizeof(ins));
	dfs_clock = 0;
	for(int i = 1; i <= n; ++i) {
		if(!dfn[i]) {
			if(!tarjan(i, x)){
				// cout << i <<" " <<x<< endl;
				return false;
			}
		}
	}

	// if(col_cnt < n) return false;
	// else return true;
	return true;
}


int main() {
	scanf("%d %d", &n, &m);
	int r = 0;
	for(int i = 1, la, lb, lc; i <= m; ++i) {
		scanf("%d %d %d", &la, &lb, &lc);
		adde(la, lb, lc);
		r = max(r, lc);
	}
	int l = 0;
	int ans = r;
	while(l <= r) {
		int mid = l + ((r - l) >> 1);
		if(check(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans <<endl;

	return 0;
}