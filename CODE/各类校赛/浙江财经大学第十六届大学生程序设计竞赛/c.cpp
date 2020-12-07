#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

struct Mon {
	int index, x, y;
	bool operator < (const Mon &rhs) const {
		if(index == rhs.index) {
			return y < rhs.y;
		} else return index < rhs.index;
	}
};

int main() {
	int n;
	cin >> n;
	vector <Mon> p;
	for(int i = 1; i <= n; ++i) {
		Mon la;
		scanf("%d %d %d", &la.index, &la.x, &la.y);
		p.emplace_back(la);
	}
	sort(p.begin(), p.end());
	ll num = 0;
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		// cout << p[i].y << endl;
		if(i != 0 && p[i].index != p[i - 1].index) {
			num = 1;
			ans += p[i].x;
		} else {
			ans += num * p[i].y + p[i].x;
			num += 1;
		}
	}
	cout << ans <<endl;
	return 0;
}
/*
4
5 9 100
7 8 1
3 10 50
2 50 10
*/