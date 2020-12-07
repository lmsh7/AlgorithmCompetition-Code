#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair <long long, long long > Pii;

const int N = 1e5 + 10;

ll val[N];
ll du[N];

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <Pii> vec;
		// memset(du, 0, sizeof(du));
		for(int i = 1; i <= n; ++i) cin >> val[i];
		for(int i = 1; i <= n - 1; ++i) {
			int la, lb;
			cin >> la >> lb;
			du[la] ++;
			du[lb] ++;
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += val[i];
			du[i] -= 1;
			if(du[i] != 0)
				vec.emplace_back(make_pair(val[i], i));
		}
		cout << ans << " ";
		sort(vec.begin(), vec.end());
		int top = vec.size() - 1;
		for(int i = 2; i <= n - 1; ++i) {
			while(du[vec[top].second] <= 0 && top != 0) {
				top --;
			}
			du[vec[top].second] -= 1;
			ans += vec[top].first;
			cout << ans <<" ";
		}
		cout << endl;
	}
	return 0;
}