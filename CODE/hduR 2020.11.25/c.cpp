#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e3 + 1;

int a[N][N];
int max_h[N][N];
int q[N], p[N];
int main() {
	int n, w, h, A, B;
	long long P;
	cin >> n >> w >> h >> A >> B >> P;
	for(int i = 1; i <= n; ++i) {
		cin >> a[1][i];
	}

	for(int i = 2; i <= n; ++i) {
		cin >> a[i][1];
		for(int j = 2; j <= n; ++j) {
			a[i][j] = ((1LL * A * a[i - 1][j]) % P + (1LL * B * a[i][j - 1]) % P ) % P;
		}
	}

	for(int i = 1; i <= n; ++i) {
		int head = 1, tail = 0;
		for(int j = 1; j <= n; ++j) {
			while(head <= tail && q[tail] < a[i][j]) {
				tail--;
			}
			q[++tail] = a[i][j];
			p[tail] = j;
			while(head <= tail && p[head] < j - h + 1) {
				head ++;
			}
			max_h[i][j] = q[head];
		}		
	}
	// for(int i = 1; i <= n; ++i) {
	// 	for(int j = 1; j <= n; ++j) {
	// 		printf("%d ", max_h[i][j]);
	// 	}
	// 	puts("");
	// }

	long long ans = 0;
	for(int j = h; j <= n; ++j) {
		int head = 1, tail = 0;
		for(int i = 1; i <= n; ++i) {
			while(head <= tail && q[tail] < max_h[i][j]) {
				tail--;
			}
			q[++tail] = max_h[i][j];
			p[tail] = i;
			while(head <= tail && p[head] < i - w + 1) {
				head ++;
			}
			if(i >= w) {
				ans += q[head];
			}
		}
	}
	cout << ans <<endl;

	return 0;
}