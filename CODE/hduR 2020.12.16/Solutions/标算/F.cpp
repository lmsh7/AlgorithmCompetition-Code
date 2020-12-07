#include <bits/stdc++.h>
#define N 1000007
using namespace std;

inline int rd() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar())
    x = x * 10 + (c ^ 48);
  return f ? -x : x;
}

int n, m, tot, hd[N], deg[N];

struct road {int u, v, w;}a[N];

struct edge {int w, to, nxt;}e[N];

inline void add(int u, int v, int w) {
  a[++tot] = (road){u, v, w};
  e[tot].to = v; e[tot].w = w;
  e[tot].nxt = hd[u]; hd[u] = tot;
}

queue<int> q;

inline bool valid(int x) {
  for (int i = 1; i <= n; ++i) deg[i] = 0;
  for (int i = 1; i <= m; ++i)
    if (a[i].w > x) ++deg[a[i].v];
  for (int i = 1; i <= n; ++i)
    if(!deg[i]) q.push(i);
  int cnt = 0;
  while(!q.empty()) {
  	++cnt;
    int u = q.front(); q.pop();
    for (int i = hd[u], v; i; i = e[i].nxt)
      if (e[i].w > x) {
        --deg[v = e[i].to];
        if (!deg[v]) q.push(v);
      }
  }
  return (cnt == n);
}

int main() {
  n = rd(); m = rd();
  int l = 0, r = 0;
  for (int i = 1, u, v, w; i <= m; ++i) {
    u = rd(); v = rd();
    r = max(r, (w = rd()));
    add(u, v, w);
  }
  while (l < r) {
    int mid = (l + r) >> 1;
    valid(mid) ? r = mid : l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}