#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

int l[N], r[N];
int q[N];


int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	int ans = 0;
	int head = 1;
	int tail = 0;
	for(int i = 1; i <= n; ++i) {
		while(head <= tail && r[i] < l[q[head]]) head++;
		// printf("i = %d q[head] = %d\n", i, q[head]);
		if(head <= tail) ans = max(ans, i - q[head] + 1);		
		int t = i;
		while(head <= tail && l[i] > l[q[tail]]) {
			t = q[tail];
			tail--;
		}
		l[t] = l[i];
		q[++tail] = t;
	}
	cout << ans <<endl;
	return 0;
}  