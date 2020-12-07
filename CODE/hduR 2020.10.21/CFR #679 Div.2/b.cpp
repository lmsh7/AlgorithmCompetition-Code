#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;


typedef long long ll;
typedef unsigned long long ull;

const int N = 105;

int a[N];

int main() {
	int T;
	cin >> T;
	int n, m;
	while (T--) {
		cin >> n >> m;
		int tmp;
		map <int, int> mp;
		vector <int> row[505];
		rep(i, 1, n)
			rep(j, 1, m) {
				scanf("%d", &tmp);
				row[i].push_back(tmp);
				mp.insert(pair<int, int>{tmp, i});
			}
		rep(i, 1, m)
			rep(j, 1, n) {
				scanf("%d", &tmp);
				if(i == 1) {
					for(auto qwq: row[mp.find(tmp)->second]) {
						printf("%d ", qwq);
					}
					printf("\n");
				}
			}

	}
	return 0;
}