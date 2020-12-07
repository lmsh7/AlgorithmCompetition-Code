#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		int sum = 0;
		for(int i = 1, la; i <= n; ++i) {
			cin >> la; 
			sum = sum ^ la;
		}
		if(sum == 0) puts("No");
		else puts("Yes");
	}
	return 0;
}