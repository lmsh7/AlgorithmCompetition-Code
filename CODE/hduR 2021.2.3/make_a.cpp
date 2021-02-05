#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("1.in", "w", stdout);
	int n, m;
	srand(time(0));
	n = 200000;
	m = 500000;
	cout << n << " "<< m << endl;
	for(int i = 1; i <= m; ++i) {
		int opt = rand() % 2;
		int x = rand() % n + 1;
		cout <<opt<< " " << x <<endl;
	}
}