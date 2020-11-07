#include <bit/stdc++.h> 
using namespace std;

const int N = 305;
const int dx[] = {0, 1};
const int dy[] = {1, 0};


int a[N][N];
int f[N << 1][N][N];

int n;

bool check(int x, int y) {
	if(x > n || y > n) return true;
	else return false;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	f[0][1][1] = 1;
	for(int k = 0; k <= (2 * n - 2); ++k)
		for(int i = 1; i <= min(k, n); ++i)
			for(int j = 1; j <= min(k, n); ++j) {
				int x1 = i;
				int x2 = j;
				int y1 = k - (x1 - 1) + 1;
				int y2 = k - (x2 - 1) + 1;
				for(int d1 = 0; d1 <= 1; ++d1)
					for(int d2 = 0; d2 <= 2; ++d2) {
						int x3 = x1 + dx[d1];
						int x4 = x2 + dx[d2];
						int y3 = y1 + dy[d1];
						int y4 = y2 + dy[d2];
						if(check(x3, y3) || check(x4, y4) || (a[x4][y4] != a[x3][y3])) continue;
						f[k + 1][x3][x4] = f[k][x1][x2] + 1;
					}
			}
	return 0;
}