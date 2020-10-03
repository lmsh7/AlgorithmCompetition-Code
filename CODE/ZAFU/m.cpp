#include <bits/stdc++.h>
using namespace std;


const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


struct Node {
	int x, y, mii;
	bool operator > (const Node x) const {
		return mii < x.mii;
	}
};

typedef pair <int, Node> Pair;

int h[1005][1005];
int vis[1005][1005];
int mi[1005][1005];

int n;

inline bool check(int x, int y) {
	if(x <= 0 || x > n || y <= 0 || y > n) return false;
	else return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &h[i][j]);
			// mi[i][j] = h[i][j];
		}
	mi[1][1] = h[1][1];
	priority_queue <Node, vector<Node>, greater<Node>> q;
	q.push(Node{1,1,h[1][1]});
	while(!q.empty()) {
		Node u = q.top();
		q.pop();
		if(vis[u.x][u.y]) continue;
		vis[u.x][u.y] = 1;
		
		// printf("%d %d %d\n", u.x, u.y, u.mii);
		for(int i = 0; i <= 3; ++i) {
			Node v;
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			 // printf("a%d %d\n", v.x, v.y);
			if(check(v.x, v.y) && !vis[v.x][v.y]) {//小小剪枝就过
				// cout <<"fufc"<<endl;
				
				mi[v.x][v.y] = max(mi[v.x][v.y], min(mi[u.x][u.y], h[v.x][v.y]));
				// printf("a%d %d mi = %d\n", v.x, v.y, mi[v.x][v.y]);
				 q.push(Node{v.x, v.y, mi[v.x][v.y]});
			}
		}
	}
	int f, x;
	cin >> f;
	// for(int i = 1; i <= n; ++i)
	// 	for(int j = 1; j <= n; ++j) {
	// 		printf("mi[%d][%d] = %d\n",i,j, mi[i][j]);
	// 		// mi[i][j] = h[i][j];
	// 	}
	// cout << mi[n][n];
	for(int i = 1; i <= f; ++i) {
		scanf("%d", &x);
		if(x > mi[n][n]) {
			puts("Hmmm");
		} else puts("Wuhu");
	}

	return 0;
}