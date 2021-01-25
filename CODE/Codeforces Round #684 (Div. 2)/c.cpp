/*
* @Author: LMSH7
* @Date:   2021-01-05 18:34:28
* @Last Modified by:   LMSH7
* @Last Modified time: 2021-01-11 21:10:08
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;


const int N = 105;

int n, m;

char a[N][N];

struct Node {
	int x1, y1, x2, y2, x3, y3;
};

vector <Node> vec;


int _count(int x, int y) {
	int num = 0;
	for(int i = x; i >= x - 1; --i)
		for(int j = y ; j >= y - 1; --j) {
			num += a[i][j] - '0';
		}
	return num;
}

void solve(int num, int x, int y) {
	// printf("%d %d %d\n", num, x, y);
	// 	for(int i = x - 1; i <= x; ++i) {
	// 		for(int j = y - 1; j <= y; ++j) {
	// 			cout << a[i][j] <<" ";
	// 		}	
	// 		cout << endl;		
	// 	}

	if(num == 0) {
		return;
	} else if(num == 3) {
		int lx[3];
		int ly[3];
		int cnt = 0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '1') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				}
			}
		vec.emplace_back(Node{lx[0], ly[0], lx[1], ly[1], lx[2], ly[2]});
		a[lx[0]][ly[0]] = '0';
		a[lx[1]][ly[1]] = '0';
		a[lx[2]][ly[2]] = '0';
	} else if(num == 2) {
		int lx[3];
		int ly[3];
		int cnt = 0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '1') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				}
			}
		if(lx[0] != lx[1] && ly[0] != ly[1]) {
			int lx0[2];
			int ly0[2];
			int cnt0 = 0;
			for(int i = x; i >= x - 1; --i)
				for(int j = y ; j >= y - 1; --j) {
					if(a[i][j] == '0') {
						lx0[cnt0] = i;
						ly0[cnt0] = j;
						++cnt0;
					}
				}
			vec.emplace_back(Node{lx0[0], ly0[0], lx0[1], ly0[1], lx[0], ly[0]});
			a[lx0[0]][ly0[0]] = '1';
			a[lx0[1]][ly0[1]] = '1';
			a[lx[0]][ly[0]] = '0';
			solve(3, x, y);
			return;
		} else {	
			int lx0[3];
			int ly0[3];
			int	cnt0 = 0;
			for(int i = x; i >= x - 1; --i)
				for(int j = y ; j >= y - 1; --j) {
					if(a[i][j] == '0') {
						lx0[cnt0] = i;
						ly0[cnt0] = j;
						++cnt0;
					}
				}
			vec.emplace_back(Node{lx0[0], ly0[0], lx0[1], ly0[1], lx[0], ly[0]});
			a[lx0[0]][ly0[0]] = '1';
			a[lx0[1]][ly0[1]] = '1';
			a[lx[0]][ly[0]] = '0';
			solve(3, x, y);
		}
	} else if(num == 1) {
		int lx[3];
		int ly[3];
		int cnt = 0;
		int lx0;
		int ly0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '0') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				} else if(a[i][j] == '1') {
					lx0 = i;
					ly0 = j;
				}
			}
		if(lx[0] != lx[1] && ly[0] != ly[1]) {
			lx[1] = lx[2];
			ly[1] = ly[2];
		}
		vec.emplace_back(Node{lx[0], ly[0], lx[1], ly[1], lx0, ly0});
		a[lx[0]][ly[0]] = '1';
		a[lx[1]][ly[1]] = '1';
		a[lx0][ly0] = '0';
		solve(2, x, y);
	} else if(num == 4) {
		int lx[5];
		int ly[5];
		int cnt = 0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '1') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				}
			}
		vec.emplace_back(Node{lx[0], ly[0], lx[1], ly[1], lx[2], ly[2]});
		a[lx[0]][ly[0]] = '0';
		a[lx[1]][ly[1]] = '0';
		a[lx[2]][ly[2]] = '0';
		solve(1, x, y);
	} else if(num == -1) {
		if(a[x - 1][y - 1] == '0' && a[x][y - 1] == '0') return;
		else if(a[x - 1][y - 1] == '1' && a[x][y - 1] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x, y - 1, x, y});
			a[x - 1][y - 1] = '0';
			a[x][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';
		} else if(a[x - 1][y - 1] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x - 1, y, x, y});
			a[x - 1][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x - 1][y] == '1') a[x - 1][y] = '0';
			else a[x - 1][y] = '1';		
		} else if(a[x][y - 1] == '1') {
			vec.emplace_back(Node{x, y - 1, x - 1, y, x, y});
			a[x][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x - 1][y] == '1') a[x - 1][y] = '0';
			else a[x - 1][y] = '1';	
		}
	} else if(num == -2) {
		if(a[x - 1][y - 1] == '0' && a[x - 1][y] == '0') return;
		else if(a[x - 1][y - 1] == '1' && a[x - 1][y] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x - 1, y, x, y});
			a[x - 1][y - 1] = '0';
			a[x - 1][y] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';
		} else if(a[x - 1][y - 1] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x, y - 1, x, y});
			a[x - 1][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x][y - 1] == '1') a[x][y - 1] = '0';
			else a[x][y - 1] = '1';		
		} else if(a[x - 1][y] == '1') {
			vec.emplace_back(Node{x - 1, y, x, y - 1, x, y});
			a[x - 1][y] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x][y - 1] == '1') a[x][y - 1] = '0';
			else a[x][y - 1] = '1';	
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vec.clear();
		for(int i = 1; i <= n; ++i) 
			scanf("%s", a[i] + 1);
		for(int i = 2; i <= n; i + 2 > n ? i += 1 : i += 2) {
			for(int j = 2; j <= m; j + 2 > m ? j += 1 : j += 2) {
				
				// cout << i << " " <<j <<endl;
				if(j + 2 > m && j != m) solve(-1, i, j);
				else if(i + 2 > n && i != n) solve(-2, i, j);
				else solve(_count(i, j), i, j);
			}
		}
		cout << vec.size() <<endl;
		if(vec.size() == 0) continue;
		for(int i = 0; i <= vec.size() - 1; ++i) {
			printf("%d %d %d %d %d %d\n", vec[i].x1, vec[i].y1, vec[i].x2, vec[i].y2, vec[i].x3, vec[i].y3);
		}
		// for(int i = 1; i <= n; ++i) {
		// 	printf("%s\n", a[i] +1);
		// }

	}
}