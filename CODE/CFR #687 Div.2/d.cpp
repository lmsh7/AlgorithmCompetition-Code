#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
int a[N];
int hBit[N];
 
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		int la = a[i];
		int cnt = 1;
		while(la) {
			hBit[i] = cnt;
			la >>= 1;
			cnt ++;
		}
	}
	int ans = 0;
	for(int i = 3; i <= n; ++i) {
		if(hBit[i] == hBit[i - 1] && hBit[i - 1] == hBit[i - 2]) {
			ans = 1;
		}
	}
	if(ans) {
		cout << ans << endl;
		return 0;
	}
	for(int k = 2; k <= n; ++k) {
		for(int l = 1; (l + k - 1) <= n; ++l) {
			int r = l + k - 1;
			for(int mid = l; mid < r; ++mid) {
				int cl, cr;
				for(int i = l; i <= mid; ++i) {
					if(i == l) cl = a[i];
					else cl ^= a[i];
				}
				for(int i = mid + 1; i <= r; ++i) {
					if(i == mid + 1) cr = a[i];
					else cr ^= a[i];
				}
				if(cl > cr) {
					 // printf("%d %d l = %d r = %d mid = %d\n", cl, cr, l, r, mid);
					ans = (mid - l) + ( r - (mid + 1));
					break;
				}
			}				
			if(ans) break;
		}		
		if(ans) break;
	}
 
	if(ans) cout << ans <<endl;
	else cout << -1 <<endl;
	return 0;
}