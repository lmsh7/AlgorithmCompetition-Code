#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n; 
		cin >> n;
		map<int, int> mp;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			for(int j = 1; j < i; ++j) {
				int qwq = a[i] - a[j];
				// if(mp[qwq] == 0) {
					mp[qwq] = 1;
					// ans ++;
				// }
			}
			
		}
		cout << mp.size() <<endl;
	}
	return 0;
}