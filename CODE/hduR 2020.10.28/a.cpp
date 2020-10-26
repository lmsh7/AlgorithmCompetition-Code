#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;

const int N = 3e5 + 10;

typedef long long ll;
typedef unsigned long long ull;

int a[N], b[N], fa[N << 1];

int find_fa(int x) {
	return x == fa[x] ? x : fa[x] = find_fa(fa[x]);
}

int main() {
		//freopen("1.out", "r", stdin);

	int n;
	scanf("%d", &n);
	int cnt = 0;
	map <int, int> mp;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		// c[i] = a[i];
		if(mp.find(a[i]) == mp.end()) {
			mp[a[i]] = ++cnt;
			a[i] = cnt;
		} else {
			a[i] = mp[a[i]];
		}
	} 
	rep(i, 1, n) {
		scanf("%d", &b[i]);
		// c[i + n] = b[i];
		if(mp.find(b[i]) == mp.end()) {
			mp[b[i]] = ++cnt;

			b[i] = cnt;
		} else {
			b[i] = mp[b[i]];
		}
	}
	// cout << cnt <<endl;
	for(int i = 1; i <= cnt; ++i) fa[i] = i; 
	rep(i, 1, n) {
		int faa = find_fa(a[i]);
		int fab = find_fa(b[i]);
		if(faa != fab) {
			fa[faa] = fab;
		}
	}
	sort(fa + 1, fa + cnt + 1);
	int tmp = 0;
	int ans = 0;
	rep(i, 1, cnt) {
		find_fa(i);
	}
	rep(i, 1, cnt + 1) if(fa[i] != fa[i - 1] && i != 1) {
		ans += tmp - 1;
		tmp = 1;
	} else {tmp ++;}
	printf("%d", ans);
	return 0;
}