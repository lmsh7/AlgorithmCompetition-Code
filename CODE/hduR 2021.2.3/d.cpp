#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

int a[N];

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		int numA = 0;
		int numB = 0;
		for(int i = n; i >= 2; --i) {
			 numB ++;
		}
		if(numA == 0) numA = a[1];
		if(numA % 2 == 1 && numB % 2 == 0) {
			puts("Second");
		} else if(numA % 2 == 1 && numB % 2 == 1) {
			puts("First");
		} else if(numA % 2 == 0 && numB % 2 == 0) {
			puts("First");
		} else if(numA % 2 == 0 && numB % 2 == 1) {
			puts("Second");
		}
	}
	return 0;
}