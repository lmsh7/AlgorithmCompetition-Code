#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

int l[N], r[N];
int st[N][20];

int st_max(int x, int y) {
	int loglen = log2(y - x + 1);
	return max(st[x][loglen], st[y - (1 << loglen) + 1][loglen]);
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	//R[i] > max(a[j] ~ a[i])
	for(int k = 0; (1 << k) <= n; ++k)
		for(int j = 1; (j + (1 << k) - 1) <= n; ++j) {
			if(k == 0) st[j][k] = l[j];
			else st[j][k] = max(st[j][k - 1], st[j + (1 << (k - 1))][k - 1]);
		}	
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int L = 1, R = i;
		int mid;		
		int tmp_ans = i;
		while(L <= R) {
			mid = L + ((R - L) >> 1);
			printf(" i = %d mid = %d\n", i, mid);
			if(r[i] > st_max(mid, i)) {
				R = mid - 1;
				tmp_ans = min(tmp_ans, mid);
			} else {
				L = mid + 1;
			}
		}
		ans = max(i - tmp_ans + 1, ans);
	}
	for(int i = 1; i <= n; ++i) {
		while(head <= tail && zao[i] >= q[tail]) {
			tail--;
		}
		ans = max(ans, q[head]);
	}
	return 0;
}  