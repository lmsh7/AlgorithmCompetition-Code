#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;


int head[N];
int ecnt;
int dep[N], fa[N], a[N];

struct Edge {
	int to, next;
} e[N << 1];

inline void adde(int x, int y) {
	e[++ecnt] = Edge{y, head[x]};
	head[x] = ecnt;
}

char query(int x, int y) {
	int cnt = 0;
	vector <int> vec;
	while(cnt <= 50) {
		if(dep[x] < dep[y]) swap(x, y);
		vec.emplace_back(a[x]);
		if(x == y) break;
		cnt ++;
		x = fa[x];
	}
	if(cnt > 50) return 'Y';
	sort(vec.begin(), vec.end());
	if(vec.size() <= 2) return 'N';
	for(int i = 2; i <= vec.size() - 1; ++i) {
		if(vec[i - 2] > vec[i] - vec[i - 1]) return 'Y';
	}
	return 'N';
}

void dfs(int x) {
	dep[x] = dep[fa[x]] + 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v != fa[x]) {
			fa[v] = x;
			dfs(v);
		}
	} 
	return;
}

int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1, la, lb; i <= n - 1; ++i) {
		cin >> la >> lb;
		adde(la, lb);
		adde(lb, la);
	}
	dfs(1);
	for(int i = 1; i <= q; ++i) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if(opt == 1) {
			a[x] = y;
		} else {
			cout << query(x, y) << endl;
		}
	}
	return 0;
}