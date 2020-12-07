#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
const int INF = 2147483647;
 
int  num[N];
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, p, k, x, y;
		string s;
		cin >> n >> p >> k;
		cin >> s >> x >> y;
		int  ans = INF;
		p -= 1;
		memset(num, 0, sizeof(num));
		for(int i = 0; i < n; ++i) {
			if(i >= p) num[(i - p) % k] += ('1' - s[i]);
		}
		for(int i = p; i < n; ++i) {
			ans = min(num[(i - p) % k] * x + y * (i - p), ans);
			if(s[i] == '0') num[(i - p) % k] -= 1;
		}
		cout << ans <<endl;
 
	}
	return 0;
}
/*
1
10 3 3
0000000100
80 1
*/