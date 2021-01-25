#include <bits/stdc++.h>
#define int long long 
using namespace std;

bool check(int x) {
	int w = 10;
	int dig = x % w;
	int num = x;
	while(x) {


		if(dig != 0 && num % dig != 0) return false;
		x /= 10;
		dig = x % w;
	}

	return true;
}

signed main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		while(!check(num)) {
			num++;
		}
		printf("%lld\n",num);
	}
	return 0;
}