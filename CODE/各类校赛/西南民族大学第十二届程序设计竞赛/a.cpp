#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

char a[11][11];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int dis[3][15][15];
int n, m;
vector <int> vec[3];

void bfs(int x, int sx, int sy) {
    dis[x][sx][sy] = 0;
    queue <pii> q;
    q.push({sx, sy});
    while(!q.empty()){
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();    	
        // cout << ux << " " << uy <<endl;

        if(a[ux][uy] == '@') {
            // vec[x].emplace_back(dis[x][ux][uy]);
            continue;
        }
        for(int i = 0; i <= 3; ++i) {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(vx > n || vx <= 0 || vy > m || vy <= 0 || a[vx][vy] == '#') continue;
            if(dis[x][vx][vy] == 1061109567) {
                q.push({vx, vy});
                dis[x][vx][vy] = dis[x][ux][uy] + 1;
            }
        }
    }
}

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'H') {
                bfs(1, i, j);
            }
            if(a[i][j] == 'Z') {
                bfs(2, i, j);
            }
        } 
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= m; ++j) {
    		if(a[i][j] == '@') {
    			if(dis[2][i][j] >= dis[1][i][j]) ans ++;
    		}
    	}
    if(ans == 2) puts("give me northeast chicken rice and milk tea!");
    else puts("give me northeast chicken rice and milk tea TOMORROW!");
    return 0;
}