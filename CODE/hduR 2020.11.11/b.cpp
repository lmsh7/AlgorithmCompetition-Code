#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;


int f[61][61][61][3];

int n, m, K, q;

int w[61];
int d[61][61];

bool check(int x, int y) {
	if(abs(w[x] - w[y]) > K) return false;
	else return true;
}

int main() {
	cin >> n >> m >> K >> q;	
	for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
	for (int i = 1, la, lb; i <= m; ++i) {
		cin >> la >> lb;
		d[la][lb] = 1;
	}
	for(int i = n; i >= 1; --i)
		for(int j = n; j >= 1; --j) 
			for(int k = n; k >= 1; --k) {
				
					for(int t = k + 1; t <= n; ++t) 
						if(d[k][t]) f[i][j][k][2] = (f[i][j][k][2] + f[i][j][t][0]) % P;
					if(check(j, k))
						for(int t = j + 1; t <= n; ++t) 
							if(d[j][t]) f[i][j][k][1] = (f[i][j][k][1] + f[i][t][k][2]) % P;
					if(check(j, k) && check(i, k) && check(j, i)) {
						f[i][j][k][0] = 1; 
						for(int t = i + 1; t <= n; ++t) 
							if(d[i][t]) f[i][j][k][0] = (f[i][j][k][0] + f[t][j][k][1]) % P;						
					}

			}
	for (int i = 1, la, lb, lc; i <= q; ++i) {
		scanf("%d %d %d", &la, &lb, &lc);
		printf("%d\n", f[la][lb][lc][0]);
	}
	return 0;
}