#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 10;

int a[N];

struct Node {
	int q[51];
	bool operator < (const Node t) const {
		for (int i = 1; i <= 50; ++i) {
			if (q[i] == t.q[i]) continue;
			return q[i] < t.q[i];
		}
		return false;
	}
};

int sum[60][N];

map <Node, int> mp;
Node tmp;
int n, m;

int main() {
	cin >> n >> m;
	mp.insert(pair<Node , int>(tmp, 1));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= m; ++j) {
			sum[j][i] = sum[j][i - 1];
			tmp.q[j] = 0;
		}
		sum[a[i]][i] += 1;
		for (int j = 1; j <= m; ++j) {
			tmp.q[j] = i - m * sum[j][i];
		}
		if (mp.find(tmp) != mp.end()) {
			mp[tmp]++;
		} else mp.insert(pair<Node , int>(tmp, 1));
	}
	int ans = 0;
	for (auto i : mp) {
		int x = i.second;
		if (x > 1) ans += (1LL * x * (x - 1)) / 2;
	}
	cout << ans << endl;
	return 0;
}