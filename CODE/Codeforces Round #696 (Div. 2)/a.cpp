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
		int qian = 0;
		for(int i = 0; i <= n - 1; ++i) {
			if(i == 0) {
				cout << 1;
				qian = a[i] - '0' + 1;
			} else {
				if(qian == a[i] - '0' + 1) {
					cout << 0;
					qian = a[i] - '0' + 0;
				} else {
					cout << 1;
					qian = a[i] - '0' + 1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}