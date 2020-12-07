#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 105;

int a[N];

int main() {
	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;

		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		for(int i = 1; i <= n / 2; ++i) {
			printf("%d ", -a[n - i + 1]);
		}
		for(int i = n / 2 + 1; i <= n; ++i) {
			printf("%d ", a[n - i + 1]);
		}
		printf("\n");

	}
	return 0;
}