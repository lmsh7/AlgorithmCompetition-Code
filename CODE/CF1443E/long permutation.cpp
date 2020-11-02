#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
ll fac[16];
ll sum;
ll a[16];
int p[16];
int vis[16];
int n, q;
 
void get(ll qwq) {//很巧妙的得到字典序排列的方法
	for(int i = 1; i <= 14; ++i) {
		a[i] = qwq / fac[15 - i];
		qwq %= fac[15 - i];
	}//得到排列
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= 15; ++i) {
		int cnt = 0;
		for(int j = 1; j <= 15; ++j) {
			if(!vis[j]) ++cnt;//未记录过的数才计入
			if(cnt == a[i] + 1) {
				vis[j] = 1;
				p[i] = j;
				break;
			}
		}
	}
}
 
int main() {
	fac[0] = 1; 
	rep(i, 1, 15) fac[i] = fac[i - 1] * i;//预处理阶乘
	scanf("%d %d", &n, &q);
	while(q--) {
		int opt;
		long long ans = 0;
		scanf("%d", &opt);
		if(opt == 1) {
			int l, r;
			scanf("%d %d", &l, &r);
			if(r > n - 15) {
				get(sum);
				ans = 0;
				if(l > n - 15) {
					for(int i = l - (n - 15); i <= r - (n - 15); ++i) {
						ans += p[i];
						// printf("%d\n", p[i]);
					}
					ans += (r - l + 1) * (n - 15);
				} else {
					for(int i = 1; i <= r - (n - 15); ++i) {
						ans += p[i];
					}
					ans += 1LL * (r - (n - 15)) * (n - 15);
					ans += 1LL * (n - 15 - l + 1) * (l + n - 15)/ 2;
				}
				cout << ans <<endl;
			} else {
				ans = 1LL * (l + r) * (r - l + 1) / 2;
				cout << ans <<endl;
			}
		} else {
			int x;
			scanf("%d", &x);
			sum += x;
		}
	}
	return 0;
}