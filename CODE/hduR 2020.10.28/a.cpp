#include <bits/stdc++.h>
using namespace std;

int find_fa(vector<int>& dsu, int x) {
	return x == dsu[x] ? x : dsu[x] = find_fa(dsu, dsu[x]);
} 

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n), vec;
	for(int &x: a) {scanf("%d", &x); vec.emplace_back(x);}
	for(int &x: b) {scanf("%d", &x); vec.emplace_back(x);}
	sort(begin(vec), end(vec));
	vec.erase(unique(begin(vec), end(vec)), end(vec));
	for(int &x: a) x = lower_bound(begin(vec), end(vec), x) - begin(vec);
	for(int &x: b) x = lower_bound(begin(vec), end(vec), x) - begin(vec);
	vector <int> dsu(vec.size());
	for(int i = 0; i < (int)vec.size(); ++i) dsu[i] = i;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(find_fa(dsu, b[i]) != find_fa(dsu, a[i])) {
			ans += 1;
			dsu[dsu[b[i]] = a[i];
		}
	}
	cout << ans <<endl;
}