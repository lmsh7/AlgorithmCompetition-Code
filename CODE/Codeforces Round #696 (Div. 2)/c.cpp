#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int A = 1e6 + 10;
const int N = 2e3 + 10;

int n;
int a[N];
int vis[A];

struct Ans {
	int a, b;
} ans[N];

void reset() {
	for(int i = 1; i <= 2 * n; ++i) {
		vis[a[i]] = 0;
	}
	for(int i = 1; i <= 2 * n; ++i) {
		vis[a[i]]++;
	}
	return;
}

bool cmp(int x, int y) {
	return x > y;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	memset(vis, 0, sizeof(vis));
	sort(a + 1, a + 2 * n + 1, cmp);
	for(int i = 2; i <= 2 * n; ++i) {
		reset();
		int x = a[1] + a[i];
		int j = 1;
		int flag = 1;
		for(int op = 1; op <= n; ++op) {
			while(j <= 2 *n && vis[a[j]] == 0) ++j;
			ans[op].a = a[j]; 
			ans[op].b = x - a[j];
			vis[a[j]] --;
			vis[x - a[j]] --;
			
			if(vis[a[j]] < 0 || vis[x - a[j]] < 0) {
				break;
			}
			x = max(a[j], x - a[j]);
			if(op == n) {
				flag = 0;
			}
		}
		if(flag == 0) {
			puts("YES");
			cout << ans[1].a+ ans[1].b <<endl;
			for(int q = 1; q <= n; ++q) {
				cout << ans[q].a <<" " <<ans[q].b <<endl;
			}
			// for(int q = 1; q <= n * 2; ++q) {
			// 	cout << vis[a[q]] <<" ";
			// }
			// cout << endl;
			return;
		}
	}
	puts("NO");
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

/*
2
1 3 3 5
2
1 3 3 5
2
1 3 3 5
2
1 3 3 5



126
2
1 1 1 1
2
1 1 1 2
2
1 1 1 3
2
1 1 1 4
2
1 1 1 5
2
1 1 1 6
2
1 1 2 2
2
1 1 2 3
2
1 1 2 4
2
1 1 2 5
2
1 1 2 6
2
1 1 3 3
2
1 1 3 4
2
1 1 3 5
2
1 1 3 6
2
1 1 4 4
2
1 1 4 5
2
1 1 4 6
2
1 1 5 5
2
1 1 5 6
2
1 1 6 6
2
1 2 2 2
2
1 2 2 3
2
1 2 2 4
2
1 2 2 5
2
1 2 2 6
2
1 2 3 3
2
1 2 3 4
2
1 2 3 5
2
1 2 3 6
2
1 2 4 4
2
1 2 4 5
2
1 2 4 6
2
1 2 5 5
2
1 2 5 6
2
1 2 6 6
2
1 3 3 3
2
1 3 3 4
2
1 3 3 5
2
1 3 3 6
2
1 3 4 4
2
1 3 4 5
2

...
Output
NONO
YESYES
33
2 12 1
1 11 1
NONO
NONO
NONO
NONO
YESYES
44
2 22 2
1 11 1
YESYES
44
3 13 1
2 12 1
NONO
NONO
NONO
NONO
YESYES
55
4 14 1
3 13 1
NONO
NONO
NONO
YESYES
66
5 15 1
4 14 1
NONO
NONO
YESYES
77
6 16 1
5 15 1
NONO
NONO
YESYES
55
3 23 2
2 12 1
YESYES
55
4 14 1
2 22 2
NONO
NONO
YESYES
66
3 33 3
2 12 1
YESYES
66
4 24 2
3 13 1
YESYES
66
5 15 1
3 23 2
NONO
NONO
YESYES
77
5 25 2
4 14 1
YESYES
77
6 16 1
4 24 2
NONO
YESYES
88
6 26 2
5 15 1
NONO
NONO
YESYES
77
4 34 3
3 13 1
YESNO
8YES
5 37
3 26 1
YES3 3
7YES
6 18
3 34 4
YES3 1
8YES
4 48
3 15 3
YES4 1
8NO
5 3NO
4 1YES
NO9
NO6 3
YES5 1
9NO
6 3NO
5 1YES
NO9
NO5 4
YES4 1
9NO
5 4YES
4 110
NO5 5
YES4 1
10YES
5 510
4 16 4
YE...5 ...
Answer
NO
YES
3
2 1
1 1
NO
NO
NO
NO
YES
4
2 2
1 1
YES
4
3 1
2 1
NO
NO
NO
NO
YES
5
4 1
3 1
NO
NO
NO
YES
6
5 1
4 1
NO
NO
YES
7
6 1
5 1
NO
NO
YES
5
3 2
2 1
YES
5
4 1
2 2
NO
NO
YES
6
3 3
2 1
YES
6
4 2
3 1
YES
6
5 1
3 2
NO
NO
YES
7
5 2
4 1
YES
7
6 1
4 2
NO
YES
8
6 2
5 1
NO
NO
YES
7
4 3
3 1
NO
YES
7
6 1
3 3
YES
8
4 4
3 1
YES
8
5 3
4 1
NO
NO
YES
9
6 3
5 1
NO
NO
YES
9
5 4
4 1
NO
YES
10
5 5
4 1
YES
10
6 4
5 ...
*/