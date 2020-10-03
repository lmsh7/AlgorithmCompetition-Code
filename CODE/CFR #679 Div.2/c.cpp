#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;


typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10;

int b[N];
int a[10];
int cha[50];

int main() {
	rep(i, 1, 6) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	rep(i, 1, 6) 
		rep(j, 1, 6) {
			if(a[i] > a[j]) {
				cha[++cnt] = a[i] - a[j];
			}
		}
	int n;
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &b[i]);
	}
	sort(b + 1, b + n + 1);
	int mx = b[n] - b[1];
	sort(cha + 1, cha + cnt + 1);
	for(int i = cnt; i >= 1; --i) {
		if(mx >= cha[i]) {
			printf("%d\n", mx - cha[i]);
			return 0;
		}
	}
	printf("%d\n", mx);

	return 0;
}

/*
1 4 100 10 30 5
6
101 104 105 110 130 109
*/