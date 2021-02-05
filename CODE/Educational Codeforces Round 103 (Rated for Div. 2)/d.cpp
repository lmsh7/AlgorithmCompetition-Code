#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 6e5 + 10;

int fa[N];
int siz[N];

int find_fa(int x) {
	if(x == fa[x]) return fa[x];
	else {
		fa[x] = find_fa(fa[x]);
		siz[x] = siz[fa[x]];
		return fa[x];
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1 + n + 1; ++i) {
		fa[i] = i;
		siz[i] = 1;
	}
	string s;
	cin >> s;
	for(int i = 0; i <= n - 1; ++i) {
		if(s[i] == 'R') {
			int fa_a = find_fa(i + 1);
			int fa_b = find_fa(i + 2 + n + 1);
			if(fa_b == fa_a) continue;
			else {
				siz[fa_b] += siz[fa_a];
				fa[fa_a] = fa[fa_b];
			}
		} else {
			int fa_a = find_fa(i + 2);
			int fa_b = find_fa(i + 1 + n + 1);
			if(fa_b == fa_a) continue;
			else {
				siz[fa_b] += siz[fa_a];
				fa[fa_a] = fa[fa_b];
			}			
		}

	}
	for(int i = 1; i <= n + 1; ++i) {
		find_fa(i);
		cout << siz[i] << " ";
	}
	cout << "\n";
	return;
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
