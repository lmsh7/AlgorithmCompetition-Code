#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int a[N];

struct Node {
	int la, lb, lc;
};

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		unordered_map <int, Node> mp;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(a[j] <= a[i]) continue;
				if(mp.find(a[j] - a[i]) != mp.end()) {
					mp[a[j] - a[i]].lc = max(mp[a[j] - a[i]].lc, a[j]);
				} else mp.insert(make_pair(a[j] - a[i], Node{i, j, a[j]}));
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(j == i) continue;
				if(mp.find(a[j] + a[i]) != mp.end()) {
					if(mp[a[j] + a[i]].la != i && mp[a[j] + a[i]].la != j && mp[a[j] + a[i]].lb != i && mp[a[j] + a[i]].lb != j)
						ans = max(ans, mp[a[j] + a[i]].lc);
				}
			}
		}
		if(ans == 0) cout << "no solution" <<endl;
		else cout << ans <<endl; 
	}
	return 0;
}

