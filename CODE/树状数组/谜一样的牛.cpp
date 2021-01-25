#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

int a[N], pos[N], c[N], q[N];
int n;

inline int lowbit(int x) {
	// cout << x <<endl;
	return x & (-x);
}

void add(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i)) {
		c[i] += y;
	}
}

int query(int x) {
	int w = 0;
	if(x == 0) return 0;
	for(int i = x; i; i -= lowbit(i)) {	
		// cout << x << endl;

		w += c[i];
	}
	return w;
}

signed main() {

	cin >> n;
	a[1] = 0;
	for(int i = 2; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		add(i, 1);
		q[i] = 1;
	}
	for(int i = n; i >= 1; --i) {
		int l = 0;
		int r = n;
		while(l <= r) {

			int mid = l + ((r - l) >> 1);
			// cout << l <<  " "<< r<< " " <<mid<<endl;
			int qwq = query(mid);
			if(qwq == a[i] && q[mid + 1] == 1) {
				pos[i] = mid + 1;
				break;
			} else if(qwq < a[i]) {
				l = mid + 1;
			} else if(qwq > a[i]){
				r = mid - 1;
			} else {
				l = mid + 1;
			}

		}
		// printf("%lld: a%lld pos%lld\n", i, a[i], pos[i]);
		add(pos[i], -1);
		q[pos[i]] = 0;
		// for(int j = 1; j <= n; ++j) {
		// 	cout << c[j] << " " ;
		// }
		// cout << endl;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%lld\n", pos[i]);
	}
	return 0;
}