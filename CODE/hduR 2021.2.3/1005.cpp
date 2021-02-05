#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
	string a, b;
	cin >> a >> b;
	int flag = -1;
	if(a.length() < b.length()) {
		cout << b << endl;
		return 0;
	} else if(a.length() == b.length()) {
		for(int i = 0; i <= a.length() - 1; ++i) {
			if(a[i] > b[i]) {
				cout << 1;
				break;
			}
		}
		cout << b;
		return 0;
	}
	for(int i = 0; i <= a.length() - 1; ++i) {
		int d = 0;
		while(a[i + d] == b[d]) {
			d += 1;
		}
		if(d == b.length() && flag == -1) {
			flag = i;
		}
	}
	// if(flag == -1) {

	// 	return 0;
	// // }
	// for(int i = 0; i <= a.length() -1; ++i) {
	// 	if((a[i] == '3' || a[i] == '7') &&  (i < flag || i >= flag + b.length())) {
	// 		a[i] = a[i] + 1;
	// 	}
	// }
	// cout << a;
	return 0;
}