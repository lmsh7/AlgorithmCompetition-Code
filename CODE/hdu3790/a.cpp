#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int M = 1e5 + 5;
const int N = 1005;

int n, m, ecnt;
int head[N], vis[N], dis[N], pri[N];

struct Edge {
	int to, next, value, price;
} e[M << 1];

inline void adde(int x, int y, int z, int k) {
	e[++ecnt].to = y;
	e[ecnt].next = head[x];
	e[ecnt].value = z;
	e[ecnt].price = k;
	head[x] = ecnt;
}

void dji(int s, int t) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	memset(pri, 0x3f, sizeof(pri));
	priority_queue <pii, vector <pii>, greater<pii> > q;
	q.push(make_pair(s, 0));
	dis[s] = 0;
	pri[s] = 0;
	while(!q.empty()) {
		int u = q.top().first;
		q.pop();
		if(vis[u]) continue;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].value) {
				dis[v] = dis[u] + e[i].value;
				pri[v] = pri[u] + e[i].price;
				q.push(make_pair(v, dis[v]));
			} else if(dis[v] == dis[u] + e[i].value) {
				pri[v] = min(pri[v], pri[u] + e[i].price);
			}
		}
	}
}

int main() {
	while(1) {
		scanf("%d %d", &n, &m);
		memset(head, 0, sizeof(head));
		ecnt = 0;
		if(n == 0 || m == 0) break;
		for(int i = 1, la, lb, lc, ld; i <= m; ++i) {
			scanf("%d %d %d %d", &la, &lb, &lc, &ld);
			adde(la, lb, lc, ld);
			adde(lb, la, lc, ld);
		}		
		int s, t;
		cin >> s >> t;
		dji(s, t);
		printf("%d %d\n",dis[t], pri[t]);
	}
}