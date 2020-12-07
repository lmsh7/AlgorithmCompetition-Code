#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll Max = 1e18;


ll pre[2005];
int ans[2007];

void prework() {
	
	pre[1] = 2;
	ll fuc = 4;
	for(int i = 2; i <= 2000; ++i) {
		pre[i] = pre[i - 1] + fuc;
		fuc <<= 1;
		if(fuc > Max) break;
	}
}

int main() {
	int t;
	cin >> t;
	prework();
	// for(int i = 1; i <= 500; ++i)
	// 	printf("%lld %d\n", pre[i], i);
	while(t--) {
		ll k;
		cin >> k;
		int cnt = 0;
		int len = 0;
		if(k % 2 == 1) puts("-1");
		else {
			for(int i = 59; i >= 1; --i) {
				while(k >= pre[i]) {
					k -= pre[i];
					ans[++cnt] = i;
					len += i;
				}
			}
			printf("%d\n", len);
			for(int i = 1; i <= cnt; ++i) {
				for(int j = 1; j <= ans[i]; ++j) {
					if(j == 1) printf("1 ");
					else printf("0 ");
				}
			}
			printf("\n");

		}
	}

	return 0;
}