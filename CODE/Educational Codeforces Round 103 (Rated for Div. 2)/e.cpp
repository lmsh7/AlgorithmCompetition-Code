#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

map <string, int> mp;

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector<int>> adj(n + 1);
	vector <int> rudu(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		string la;
		cin >> la;
		mp[la] = i;
	}
	int flag = 0;
	for(int i = 1; i <= m; ++i) {
		string la;
		int mt;
		int mt_flag = 0;
		cin >> la >> mt;
		if(flag == 1) continue;
		for(int j = 0; j <= (1 << k) - 1; ++j) {
			int now = j;
			string lb = la;

			for(int z = k - 1; z >= 0; --z) {
				if(now >= (1 << z)) {
					lb[z] = '_';
					now -= (1 << z);
				}
			}
			// cout <<j << endl;
			if(mp[lb]) {
				if(mp[lb] == mt)
					mt_flag = 1;
				else {
					rudu[mp[lb]]++;
					adj[mt].emplace_back(mp[lb]);
					// if(mt == mp[lb]) {
					// 					// printf("%lld %lld %lld\n", mp[lb], i, j);

					// }
				}
			}
		}
		if(mt_flag == 0) {
			flag = 1;
			continue;
		}
	}

	if(flag == 1) puts("NO");
	else { // topo
		queue <int> q;
		vector <int> ans;
		for(int i = 1; i <= n; ++i) {
			if(rudu[i] == 0) q.push(i);
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			ans.push_back(u);
			// cout << u << endl;
			for(auto j : adj[u]) {
				rudu[j] --;
				if(rudu[j] == 0) q.push(j);
			}
		}
		if(ans.size() != n) {
			puts("NO");
		} else {
			puts("YES");
			for(auto j : ans) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}