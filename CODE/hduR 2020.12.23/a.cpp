#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10;

int n, m;

map <int, int> adj[N];

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int la, lb;
		cin >> la >> lb;
		if(!adj[la][lb]) adj[la][lb] = 1;
		if(!adj[lb][la]) adj[lb][la] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		
		int cnt = 0;
		for(auto j : adj[i]) {
			cnt++;
		}
		ans = max(ans, n - cnt - 1);
	}
	cout << ans <<endl;
	return 0;
}