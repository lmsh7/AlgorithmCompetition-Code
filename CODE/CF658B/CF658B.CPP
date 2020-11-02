#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main() {
	set<int>s;
	int n, k, q;
	cin >> n >> k >> q;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 1, la, opt; i <= q; ++i) {
		scanf("%d %d", &opt, &la);
		if(opt == 1) {
			// cout << *s.begin()<<endl;
			if((int)s.size() < k) s.insert(a[la]);
			else if(a[la] > *s.begin()) {
				s.erase(*s.begin());
				s.insert(a[la]);
			}
		} else {
			if(s.find(a[la]) != s.end()) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}