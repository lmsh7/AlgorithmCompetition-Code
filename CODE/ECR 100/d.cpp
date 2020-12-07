#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];
int b[N];

int main()d {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> b[i];
		}
		int ans = 0;
		for(int x = 0; x <= n; ++x) {
			int flag = 0;
			for(int i = 1; i <= n; ++i) {
				if(i <= x) {
					if(2 * n - b[i] - max((i - 1) * 2 - (b[i] - 1), 0) <= 0) {
						cout << x<<"A"<<b[i] <<endl;
						flag = 1;
						break;
					}

				} else {
					if(b[i] - 1 - max(b[i] - 1 - (n - i) * 2, 0)<= 0) {
						cout<<x<<"B" << b[i] <<endl;
						flag = 1;
						break;
					} 					
				}
			}
			if(flag != 1) ans++;
		}
		cout << ans <<endl;
	}
	return 0;
}