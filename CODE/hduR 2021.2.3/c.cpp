#include <bits/stdc++.h>
// #pragma GCC optimize(3)
#define int long long 
using namespace std;

const int N = 1e5 + 10;

struct Node {
	int _1, _2; 
	bool operator < (const Node &rhs) const {
		return _1 > rhs._1;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	int n, m, y;
	vector <Node> all;
	cin >> n >> y;
	for(int i = 1; i <= n; ++i) {
		int la;
		cin >> la;
		all.emplace_back(Node{la, 1});
	}
	cin >> m >> y;
	for(int i = 1; i <= m; ++i) {
		int la;
		cin >> la;
		all.emplace_back(Node{la, 2});
	}
	sort(all.begin(), all.end());
	vector<unordered_map <int, int >> mp1(33);
	vector<unordered_map <int, int >> mp2(33);
	int ans = 0;
	for(int i = 0; i <= 18; ++i) {
		int T = (1 << i);
		// cout << T << endl;
		for(Node j : all) {
			if(j._2 == 1) {
				mp1[i][j._1 % (2 * T)] ++;
				ans = max(mp1[i][j._1 % (2 * T)] + mp2[i][(j._1 + T) % (2 * T)], ans);
			} else {
				mp2[i][j._1 % (2 * T)] ++;
				ans = max(mp2[i][j._1 % (2 * T)] + mp1[i][(j._1 + T) % (2 * T)], ans);
			}
		}
	}
	cout << ans << endl;

	return 0;
}