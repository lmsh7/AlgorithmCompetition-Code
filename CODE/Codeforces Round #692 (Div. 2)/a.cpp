#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		int flag = 1;
		int num = 0;
		for(int i = a.length() - 1; i >= 0; --i) {
			if(flag && a[i] == ')') {
				num ++;
			} else {
				flag = 0;
			}
		}
		if(num > (n - num)) {
			puts("YES");
		} else puts("NO");
	}
}