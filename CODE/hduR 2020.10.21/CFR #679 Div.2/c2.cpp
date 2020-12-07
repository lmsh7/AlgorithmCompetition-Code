#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;

typedef long long ll;

const int N = 6e5 + 10;

int a[6];
int b[N];
int c[N];

int main() {
	int n;
	for(int i = 1; i <= 6; ++i) scanf("%d", &a[i]);

	int n;
	scanf("%d", &n);
	rep(i, 1, n) {//
		int tmp;
		scanf("%d", &tmp);
		rep(j, 1, 6) {
			b[6 * (i - 1) + j] = tmp - a[j];
		}
	}
	sort(b + 1, b + 6 * n + 1);
	rep(i, 1, 3 * n) {
		
	}
	return 0; 
}