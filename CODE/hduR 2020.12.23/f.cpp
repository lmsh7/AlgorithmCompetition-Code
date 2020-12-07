#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int sg[200][2];

int f (int x, int y) {
	for(int i = 0; i <= max(x, y) + 1; ++i) {
		if(i != x && i != y) return i;
	}
}

void pre(int x) {
	sg[1][0] = 1;
	sg[1][1] = 1;
	sg[2][0] = 2;
	sg[2][1] = 0;
	for(int i = 3; i <= x; ++i) {
		if(i % 2 == 1) {
			if(sg[i - 1][0]) {
				sg[i][0] = 0;	
			} else if(sg[i - 1][0] == 0) {
				sg[i][0] = 1;
			}

			if(sg[i - 1][1]) {
				sg[i][1] = 0;
			} else if(sg[i - 1][1] == 0) {
				sg[i][1] = 1;
			}

		} else {
			int la = sg[i / 2][0] ^ sg[i / 2][0];
			int lb = sg[i - 1][0];
			sg[i][0] = f(la, lb);
			la = sg[i / 2][1];
			lb = sg[i - 1][1];
			sg[i][1] = f(la, lb);
		}
	}
}

int solve(int x) {
	if(x >= 20) {
		if(x % 2 == 1) return 0;
		else {
			return f(solve(x / 2), 0);
		}
	} else return sg[x][1];
}

int main() {
	int T;
	cin >> T;
	pre(200);
	while(T--) {
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(k == 0) ans ^= (a[i] % 2 == 1 ? 1 : 0);
			else {
				if(k % 2 == 0) {//k为偶数
					if(a[i] >= 20) {
						if(a[i] % 2 == 1) ans ^= 0;
						else ans ^= 1;
					} else {
						ans ^= sg[a[i]][k % 2];
					}
				} else if(k % 2 == 1) {//k为奇数
					if(a[i] >= 20) {
						if(a[i] % 2 == 1) ans ^= 0;//a[i] 为奇数
						else ans ^= solve(a[i]);//a[i] 为偶数					
					} else {
						ans ^= sg[a[i]][k % 2];
					}

				}
				
			}
		}
		if(ans) puts("First");
		else puts("Second");
	}
}