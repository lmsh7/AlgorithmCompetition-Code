/*
* @Author: LMSH7
* @Date:   2020-12-20 16:12:53
* @Last Modified by:   LMSH7
* @Last Modified time: 2021-01-11 21:10:24
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct Opt {
	int opt;
	int a;
	int b;
} f[N];

int ans[N];
int val[N];
int fir[N];
int sum[N];
int from[N];
int to[N];
int shan[N];
int fa[N];

vector<int> vec[N];

int find_fa(int x) {
	if (fa[x] == x) return x;
	else {
		return find_fa(fa[x]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		vec[i].emplace_back(val[i]);
	}
	for (int i = 1; i <= n - 1; ++i) {
		cin >> from[i] >> to[i];
	}
	for (int i = 1; i <= m; ++i) {
		int la, lb, lc;
		cin >> la;
		if (la == 1) {
			cin >> lb;
			f[i].opt = la;
			f[i].a = lb;
			shan[lb] = 1;
		} else if (la == 2) {
			cin >> lb >> lc;
			f[i].opt = la;
			f[i].a = lb;
			f[i].b = lc;
			vec[lb].emplace_back(lc);
		} else if (la == 3) {
			cin >> lb;
			f[i].opt = la;
			f[i].a = lb;
		}
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = *(vec[i].end() - 1);
		 // cout << sum[i] <<endl;
	}
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 1; i <= n - 1; ++i) {
		if (!shan[i]) {
			int faa = find_fa(from[i]);
			int fbb = find_fa(to[i]);
			sum[fa[faa]] += sum[fa[fbb]];
			fa[fa[fbb]] = fa[faa];
		}
	}
	for (int i = m; i >= 1; --i) {
		if (f[i].opt == 2) {
sum[fa[find_fa(f[i].a)]] -= *(vec[f[i].a].end() - 1);
			sum[fa[find_fa(f[i].a)]] += *(vec[f[i].a].end() - 2);
			vec[f[i].a].erase(vec[f[i].a].end() - 1);
			// printf("sum[%d] = %d\n",fa[find_fa(f[i].a)],  sum[fa[find_fa(f[i].a)]]);
		} else if (f[i].opt == 3) {
			ans[i] = sum[find_fa(f[i].a)];
		} else {
			int enuml = f[i].a;
			int faa = find_fa(from[enuml]);
			int fbb = find_fa(to[enuml]);
			sum[fa[faa]] += sum[fa[fbb]];
			fa[fa[fbb]] = fa[faa];
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (f[i].opt == 3)
			cout << ans[i] << endl;
	}
	return 0;
}
/*

4 5
1 2 3 4
1 2
2 3
1 4
2 2 4
3 2
1 1
1 3
3 3
*/

/*
5 5
1 2 3 4 5
1 2
2 3
3 4
5 2
1 2
3 1
1 3
2 3 8
3 3
*/

/*
7 9
1 1 1 1 1 1 1
1 2
1 3
1 4
4 5
4 7
2 6
1 3
3 1
3 4
2 4 10
3 4
2 5 6
3 4
1 4
3 4

*/