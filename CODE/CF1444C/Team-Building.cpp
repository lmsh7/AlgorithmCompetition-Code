#include <bits/stdc++.h>//求总的方案数转化为求不能形成二分图的方案
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5e6 + 10;

int ecnt;
int sta = 0;
int col[N];
int fa[N];
int rak[N];
bool fuc[N];

struct OPT {
	int from, to, flag;
} opt[N];

struct Edge {
	int a, b;
	// bool operator < (const Edge x) const {
	// 	if(col[a] > col[x.a]) return col[b] < col[x.b];
	// 	else return col[a]  < col[x.a];
	// 	// return (col[a] != col[x.a]) || (col[b] != col[x.b]);
	// }//这样就是找死
} e[N];

int find_fa(int x) {
	return x == fa[x] ? x : find_fa(fa[x]);
}

void merge(int a, int b) {
	if (rak[a] < rak[b]) {
		fa[a] = b;
	} else if (rak[a] > rak[b]) {
		fa[b] = a;
	} else {
		fa[a] = b;
		rak[b] += 1;
	}
}

void merge_roll(int a, int b) {
	++sta;
	if (rak[a] < rak[b]) {
		opt[sta].from = a;
		opt[sta].to = b;
		opt[sta].flag = 0;
		fa[a] = b;
	} else if (rak[a] > rak[b]) {
		opt[sta].from = b;
		opt[sta].to = a;
		opt[sta].flag = 0;
		fa[b] = a;
	} else {
		opt[sta].from = a;
		opt[sta].to = b;
		opt[sta].flag = 1;
		fa[a] = b;
		rak[b] += 1;
	}
}

void roll_back() {
	while (sta) {
		fa[opt[sta].from] = opt[sta].from;
		if (opt[sta].flag) rak[opt[sta].to]--;
		sta--;
	}
}

bool cmp(Edge x, Edge y) {
	if (col[x.a] != col[y.a]) return col[x.a] < col[y.a];
	else return col[x.b]  < col[y.b];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= 2 * n; ++i) {
		fa[i] = i;
		rak[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &col[i]);
	}
	memset(fuc, 0, sizeof(fuc));
	for (int i = 1, la, lb; i <= m; ++i) {//求单独一个col内可否组成二分图
		scanf("%d %d", &la, &lb);
		if (col[la] == col[lb]) {
			int faa = find_fa(la);
			int fab = find_fa(lb);
			int faa_2 = find_fa(la + n);
			int fab_2 = find_fa(lb + n);
			if (faa == fab) {
				fuc[col[la]] = true;
			} else {
				merge(faa, fab_2);
				merge(faa_2, fab);
			}
		} else {
			if (col[la] > col[lb]) swap(la, lb);
			e[++ecnt].a = la;
			e[ecnt].b = lb;
		}
	}
	int kk = 0;
	ll ans = 0;
	for (int i = 1; i <= k; ++i) if (!fuc[i]) ++kk;
	ans = 1LL * kk * (kk - 1) / 2;
	int this_flag = 0;
	sort(e + 1, e + ecnt + 1, cmp);

	for (int i = 1; i <= ecnt; ++i) {
		int va = e[i].a;
		int vb = e[i].b;
		if (fuc[col[va]] || fuc[col[vb]]) continue;
		if ((i != 1) && ((col[va] != col[e[i - 1].a]) || (col[vb] != col[e[i - 1].b]))) {
			roll_back();
			this_flag = 0;
		}
		int faa = find_fa(va);
		int fab = find_fa(vb);
		int faa_2 = find_fa(va + n);
		int fab_2 = find_fa(vb + n);
		if (faa == fab) {
			if (!this_flag) {
				this_flag = 1;//防止重复判断
				ans--;
			}
		} else {
			merge_roll(faa, fab_2);
			merge_roll(faa_2, fab);
		}
	}
	cout << ans << endl;
	return 0;
}