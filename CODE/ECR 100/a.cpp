#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if((a + b + c) % 9 != 0) puts("NO");
		else if(min({a, b, c}) < (a + b + c) / 9) puts("NO");
		else puts("YES");
	}
	return 0;
}