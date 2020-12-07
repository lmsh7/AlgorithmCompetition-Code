#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int ans;
int rem;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] == 1) {
			ans += 1;
		} else if(a[i] == 2) {
			ans += 1;
			rem += 3;
		} else {
			if(rem == 0) {
				ans += 1;
				rem += 3;
			} else rem -= 1;
		}
	}
	cout << ans <<endl;
	return 0;
}