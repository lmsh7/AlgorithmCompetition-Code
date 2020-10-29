#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


bool cmp(int x, int y) {
	return x > y;
}

int a[10005];
int b[10005];

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, x;
		int flag = 1;
		cin >> n >> x;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1, cmp);
		rep(i, 1, n) {
		// cout << b[i];
			if(a[i] + b[i] > x) {
				flag = 0;
				break;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}