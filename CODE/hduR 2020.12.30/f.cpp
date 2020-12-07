#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll ans = 0;
int n;
ll now_ans;
int now_work;
int now_com;
int b[N], c[N], d[N];
void dfs(int x) {
	if(x == n + 1) {
		if(now_work >= d[x]) ans = max(ans, now_ans);
		return;
	}
	if(now_work >= d[x]) {
		int la, lb, lc;
		la = now_com;
		lb = now_work;
		lc = now_ans;
		now_com = x;
		now_work += 1;
		now_ans += c[x] + b[x];
		dfs(x + 1);
		now_com = la;
		now_work = lb;
		now_ans = lc;
	}
	now_work += 1;
	now_ans += b[now_com];
	dfs(x + 1);
	return;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> b[i];
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1; i <= n; ++i) cin >> d[i];
	for(int i = 1; i <= n; ++i) {
		now_work = 1;
		now_ans = c[i] + b[i];
		now_com = i;
		dfs(i + 1);
	}
	cout << ans <<endl;
	return 0;
}