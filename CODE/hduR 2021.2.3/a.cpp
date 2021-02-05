#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 3e5 + 10;

bool col[N], row[N];

signed main() {
	// freopen("1.in", "r", stdin);
	// 	freopen("1.out", "w", stdout);

	// ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;		
	int numc = 0;
	int numr = 0;
	int sumr = 0;
	int sumc = 0;
	int suma = n * (2 + n * n - n) / 2;
	int sumb = (n + 1) * n / 2;
	int opt;
	int c;
	int r;
	for(int i = 1; i <= m; ++i) {
		cin >> opt;
		if(opt == 1) {// column
			
			cin >> c;		
			if(col[c]) {
				cout << 0 << endl;
				continue;
			}
			col[c] = 1;
			numc += 1;
			sumc += c;
			if(numr == n) cout << 0 << endl;
			else cout << (n - numr) * (c - 1) + suma - sumr<< endl;
		} else {// row
			
			cin >> r;
			if(row[r]) {
				cout << 0 << endl;
				continue;
			}
			numr += 1;
			sumr += (r - 1) * n + 1;
			row[r] = 1;
			if(numc == n) cout << 0 << endl;
			else cout <<  (r - 1) * n * (n - numc) + sumb - sumc <<endl;
		}
	}
	return 0;
}