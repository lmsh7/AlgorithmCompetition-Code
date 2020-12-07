#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a1 = 0;
	int a2 = -1;
	for(int i = 1; i <= n; ++i) {
		string la;
		int t;
		cin >> la >> t;
		if(la[0] == 'A') {
			a1 &= t;
			a2 &= t;
		} else if(la[0] == 'O') {
			a1 |= t;
			a2 |= t;
		} else if(la[0] == 'X') {
			a1 ^= t;
			a2 ^= t;
		}
	}
	// cout <<a1 << " " <<a2 <<endl;
	int ans = 0;
	int qwq;
	for(int i = 30; i >= 0; --i) {
		if((a1 >> i) & 1) {
			ans += (1 << i);
		} else if((a2 >> i) & 1) {
			if(qwq + (1 << i) <= m) {
				ans += (1 << i);
				qwq += (1 << i);
			}
		} 
	}
	cout << ans <<endl;
	return 0;
}