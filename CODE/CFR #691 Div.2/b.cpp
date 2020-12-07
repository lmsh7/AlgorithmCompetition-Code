#include <bits/stdc++.h>
using namespace std;


int main() {
	long long  n;
	cin >> n;
	// cout << (1 + 4 * x + x * x) / (1 - x * x),;
	cout << 1 + ( 3*n*(n + 4) + 2 - pow((-1), n)  * (n*(n + 4) + 2) )/8;
	// queue <Node> q;
	// q.push(Node{500, 500, -1, 0, 0, 0});
	// while(!q.empty()) {
	// 	Node u = q.front();
	// 	q.pop();
		
	// 	if(u.step > n ) break;		
	// 	if(!vis[u.x][u.y][u.step]) {
	// 		ans[u.step] ++;
	// 		// printf("%d %d %d\n", u.x - 1000, u.y - 1000, u.step);
	// 		vis[u.x][u.y][u.step] = 1;
	// 	}
	// 	for(int i = 0; i <= 3; ++i) {
	// 		int vx = u.x + dx[i];
	// 		int vy = u.y + dy[i];
	// 		if(i == u.dir || (vx == u.fx && vy == u.fy)) continue;
	// 		q.push(Node{vx, vy, i, u.step + 1, u.x, u.y});
	// 	}
	// }
	// for(int i = 0; i <= n; ++i) {
	// 	printf("ans[%d] = %d\n", i, ans[i]);
	// }
	return 0;
}