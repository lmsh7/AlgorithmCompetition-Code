#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <long long, long long> pii;

const int N = 2e5 + 10;
const int inf = 2147483640;
const int M = 4e5 + 10;

int n, m;

int head[N], ecnt, vis[N];
ll dis[N];

struct Edge {
    ll val;
    int to, next;
} e[M << 1];

inline void adde(int x, int y, ll z) {
    e[++ecnt].to = y;
    e[ecnt].val = z;
    e[ecnt].next = head[x];
    head[x] = ecnt;
    return;
}

void dji(int x) {
    for(int i = 1; i <= n; ++i) {
        dis[i] = inf;
    }
    memset(vis, 0, sizeof(vis));
    priority_queue <pii, vector <pii>, greater <pii> > q;
    dis[x] = 0;
    q.push(make_pair(dis[x], x));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(dis[v] > dis[u] + e[i].val) {
                dis[v] = dis[u] + e[i].val;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    ll la, lb, lc;
    for(int i = 1; i <= m; ++i) {
        cin  >> la >> lb >> lc;
        lc *= 2;
        adde(la, lb, lc);
        adde(lb, la, lc);
    }
    for(int i = 1; i <= n; ++i) {
        cin >> la;
        adde(n + 1, i, la);
        adde(i, n + 1, la);
    }
    dji(n + 1);
    for(int i = 1; i <= n; ++i) {
        cout << dis[i] <<" ";
    }
    return 0;
} 