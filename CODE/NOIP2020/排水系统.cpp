#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int head[N], d[N], ru[N];
int ecnt;
__int128 ans_p[N];
__int128 ans_q[N];

__int128 gcd(__int128 a, __int128 b) {
	if(a == 0) return b;
	else return gcd(b % a, a);
}

struct Edge {
	int to, next;
} e[N * 10];

inline void adde(int x, int y) {
	e[++ecnt].to = y;
	e[ecnt].next = head[x];
	head[x] = ecnt;
}


void print(__int128 x)
{
    if (!x) return ;
    if (x < 0) putchar('-'),x = -x;
    print(x / 10);
    putchar(x % 10 + '0');
}


void dfs(int x, int p, int q) {
	// cout << x <<endl;
	if(d[x] == 0) {
		if(ans_p[x] == 0) {
			ans_p[x] = p;
			ans_q[x] = q;
		} else {
			__int128 tmp_p = ans_p[x];
			__int128 tmp_q = ans_q[x];
			ans_p[x] = tmp_q * p + q * tmp_p;
			ans_q[x] = q * tmp_q;
			__int128 fuc = gcd(ans_q[x], ans_p[x]);
			ans_p[x] /= fuc;
			ans_q[x] /= fuc;

		}
	}
	for(int i = head[x]; i; i = e[i].next) {
		dfs(e[i].to, p, q * d[x]);
	}
	return;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		for(int j = 1, la; j <= d[i]; ++j) {
			scanf("%d", &la);
			ru[la] ++;
			adde(i, la);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(ru[i] == 0) {
			dfs(i, 1, 1);
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(d[i] == 0) {
			print(ans_p[i]);
			cout << " ";
			print(ans_q[i]);
			cout << endl;
		}
	}
	return 0;
}