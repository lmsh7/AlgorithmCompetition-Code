#include <bits/stdc++.h>
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-') f = 1;
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

inline bool work() {
	int c0 = rd();
	int c1 = rd();
	int c2 = rd();
	int c3 = rd();
	if (c1 == 0 && c2 == 0) {
		if (c3 == 0) return ((c0 & 1) == 1 || c0 == 0);
		else return ((c0 & 1) == 0);
	}
	if ((c0 & 1) == 0) {
		if (c1 % 3 == 0) return 1;
		if (c1 % 3 == 1 && c2 == 0) return 1;
	} else {
		if (c1 % 3 == 1 && c2) return 1;
		if (c1 % 3 == 2 && c2 <= 1) return 1;
	}
	return 0;
}

int main() {
	int t = rd();
	while (t--) puts(work() ? "S is a hanhan" : "G is a konjac");
	return 0;
}