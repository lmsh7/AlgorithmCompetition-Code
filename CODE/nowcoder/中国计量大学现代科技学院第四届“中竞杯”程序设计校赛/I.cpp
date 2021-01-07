#include <bits/stdc++.h>
using namespace std;

const int inf = 2147483640;

const int N = 5e3 + 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, sx, sy, ex, ey, ans = inf;

string a[N];
struct Node {
    int x, y, cnt, f;
};
int vis[N][N];

int main() {
    cin >> n >> m >> sx >> sy >> ex >> ey;
    for (int i = 0; i < n; ++i) cin >> a[i];
    deque <Node> q;
    q.push_front(Node{sx, sy, 0, 4});
    while (!q.empty()) {
        Node u = q.front();
        q.pop_front();
        //printf("%d %d %d %d\n", u.x, u.y, u.cnt, u.f);
        if (vis[u.x][u.y] && vis[u.x][u.y] < u.cnt + 1) continue;
        if (u.x == ex && u.y == ey) {
            ans = u.cnt;
            break;
        }
        vis[u.x][u.y] = u.cnt + 1;
        for (int i = 0; i <= 3; ++i) {
            int vx = u.x + dx[i];
            int vy = u.y + dy[i];
            if (vy < 0 || vx < 0 || vx >= n || vy >= m) continue;
            if (a[vx][vy] == '1') continue;
            if (i == u.f || u.f == 4) {
                q.push_front(Node{vx, vy, u.cnt, i});
            } else q.push_back(Node{vx, vy, u.cnt + 1, i});
        }
        // printf("\n\n");
        // for(auto i : q) {   
        //     printf("x = %d y = %d c = %d f = %d\n", i.x, i.y, i.cnt, i.f);
        // }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j)
    //         if(a[i][j] == '0')printf("%3d ",vis[i][j]);
    //         else printf(" -1 ");
    //     printf("\n");
    // }
    if (ans == inf)  puts("-1");
    else cout << ans << endl;
    return 0;
}

/*
5 4 3 3 0 1
1011
1000
1010
1000
1111
*/