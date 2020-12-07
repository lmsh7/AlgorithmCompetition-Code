#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

struct Node {
	long long val;
	int t;
	int index;
} c[N];

bool cmp(Node a, Node b) {
	if(a.val == b.val) {
		if(a.t == b.t)
			return a.index < b.index;
		else return a.t > b.t;
	} else return a.val > b.val;
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		long long la, lb;
		cin >> la >> lb;
		c[i].val = la * lb;
		c[i].t = la;
		c[i].index = i;
	}
	sort(c + 1, c + n + 1, cmp);
	for(int i = 1; i <= n; ++i) {
		printf("%d ", c[i].index);
	}
	return 0;
}