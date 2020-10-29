#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d ;
		cout << max(a + b, c + d) << endl;
	}
	return 0;
}