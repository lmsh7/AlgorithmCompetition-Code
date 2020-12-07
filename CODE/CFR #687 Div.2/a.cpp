#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		cout << max({n - r + m - c, r - 1 + c - 1, n - r + c - 1, r - 1 + m - c}) << endl;
	}
}