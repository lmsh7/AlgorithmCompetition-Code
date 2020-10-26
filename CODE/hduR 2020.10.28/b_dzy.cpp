
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define maxn 100010
#define pb push_back
using namespace std;

int n, m;

int fa[maxn], sz[maxn]; 
void init_fa() { for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1; }

int find(int x) { return fa[x] == x ? x : find(fa[x]); } 

int st[maxn], top; 
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return ;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy; st[++top] = fx; sz[fy] += sz[fx]; 
}

inline void _undo(int _top) { 
    while (top > _top) {
        int x = st[top--];
        sz[fa[x]] -= sz[x];
        fa[x] = x; 
    }
}

struct node {
    int x, y, z;

    node() {}
    node(int _x, int _y, int _z) { x = _x; y = _y; z = _z; } 
} ; 

deque<int> e[maxn]; stack<node> S; int c1; 
inline void solve_1() {
    int x, y, fx, fy; scanf("%d%d", &x, &y);
    if (c1) return (void) (++c1, puts("NO")); 
    fx = find(x); fy = find(y);
    if (fx == fy) return (void) (c1 = 1, puts("NO")); 
    puts("YES"); S.push(node(top, x, y)); 
    if (!e[x].empty()) merge(y, e[x].front());
    e[x].push_back(y); 
    if (!e[y].empty()) merge(x, e[y].front()); 
    e[y].push_back(x); 
}

inline void solve_2() {
    if (c1) return (void) --c1;
    node u = S.top(); S.pop();
    _undo(u.x); e[u.y].pop_back(); e[u.z].pop_back(); 
} 
       
int main() {
    cin >> n >> m; init_fa(); 
    for (int i = 1; i <= m; ++i) {
        int opt; scanf("%d", &opt);
        switch (opt) {
        case 1 : solve_1(); break;
        case 2 : solve_2(); break;
        }
    } 
    return 0;
}


#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define maxn 100010
#define pb push_back
using namespace std;

int n, m;

int fa[maxn], sz[maxn]; 
void init_fa() { for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1; }

int find(int x) { return fa[x] == x ? x : find(fa[x]); } 

int st[maxn], top; 
inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return ;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    fa[fx] = fy; st[++top] = fx; sz[fy] += sz[fx]; 
}

inline void _undo(int _top) { 
    while (top > _top) {
        int x = st[top--];
        sz[fa[x]] -= sz[x];
        fa[x] = x; 
    }
}

struct node {
    int x, y, z;

    node() {}
    node(int _x, int _y, int _z) { x = _x; y = _y; z = _z; } 
} ; 

deque<int> e[maxn]; stack<node> S; int c1; 
inline void solve_1() {
    int x, y, fx, fy; scanf("%d%d", &x, &y);
    if (c1) return (void) (++c1, puts("NO")); 
    fx = find(x); fy = find(y);
    if (fx == fy) return (void) (c1 = 1, puts("NO")); 
    puts("YES"); S.push(node(top, x, y)); 
    if (!e[x].empty()) merge(y, e[x].front());
    e[x].push_back(y); 
    if (!e[y].empty()) merge(x, e[y].front()); 
    e[y].push_back(x); 
}

inline void solve_2() {
    if (c1) return (void) --c1;
    node u = S.top(); S.pop();
    _undo(u.x); e[u.y].pop_back(); e[u.z].pop_back(); 
} 
       
int main() {
    cin >> n >> m; init_fa(); 
    for (int i = 1; i <= m; ++i) {
        int opt; scanf("%d", &opt);
        switch (opt) {
        case 1 : solve_1(); break;
        case 2 : solve_2(); break;
        }
    } 
    return 0;
}