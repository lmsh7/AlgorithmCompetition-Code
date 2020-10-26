#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 1e5 + 10;

int fa[N << 1], sz[N << 1];
int n, q;
int top;
int flag;

struct STACK{
	int from, to, szflag;
} sta[N];

int find_fa(int x) {
	return x == fa[x] ? x : find_fa(fa[x]);
}

void merge(int x, int y) {
	int fax = find_fa(x);
	int fay = find_fa(y);
	if(sz[fax] < sz[fay]) {
		fa[fax] = fay;
		sta[++top].to = fay;
		sta[top].from = fax;
		sta[top].szflag = 0; 
	} else if(sz[fax] > sz[fay]) {
		fa[fay] = fax;
		sta[++top].to = fax;
		sta[top].from = fay;
		sta[top].szflag = 0; 
	} else {
		fa[fay] = fax;
		sz[fax] ++;
		sta[++top].to = fax;
		sta[top].from = fay;
		sta[top].szflag = 1; 
	}
}

void init_fa() {
	rep(i, 1, n << 1) {
		fa[i] = i;
		sz[i] = 1;
	}
}

void solve_1() {
	int x, y, fax, fay;
	scanf("%d %d", &x, &y);
	if(flag) {
		flag ++;
		puts("NO");
		return;
	}
	fax = find_fa(x); fay = find_fa(y);
	if(fax == fay) {
		flag ++;
		puts("NO");
	} else {
		puts("YES");
		merge(x, y + n);
		merge(y, x + n);
	}
}

void roll_back() {
	fa[sta[top].from] = sta[top].from;
	if(sta[top].szflag) sz[sta[top].to]--;
	top--;
	fa[sta[top].from] = sta[top].from;
	if(sta[top].szflag) sz[sta[top].to]--;
	top--;
}

void solve_2() {
	if(flag) return (void) flag--;
	roll_back();
}


int main() {
	cin >> n >> q;
	init_fa();
	rep(i, 1, q) {
		int opt;
		scanf("%d", &opt);
		switch(opt) {
			case 1: solve_1(); break;
			case 2: solve_2(); break;
		}
		// for(int i = 1; i <= n * 2; ++i) {
		// 	printf("fa[%d] = %d, sz[%d] = %d\n", i, fa[i], i, sz[i]);
		// }
	}
	return 0;
}