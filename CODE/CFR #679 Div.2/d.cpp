#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

pair <char, int> op[N];

int cnt = 0;
int ans[N];

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater <int> > q;
	for(int i = 1; i <= 2 * n; ++i) {
		char la;
		int lb;
		cin >> la;
		if(la == '-') cin >> lb;
		else lb = 0;
		op[i] = make_pair(la, lb);		
		

	}
	int flag = 0;
	for(int i = 2 * n; i >= 1; --i) {
		// cout << op[i].first <<endl;
		if(op[i].first == '-') {
			if(!q.empty() && q.top() < op[i].second) {
				flag = 1;
				break;
			}
			q.push(op[i].second);
		} else {
			if(q.empty()) {
				flag = 1;
				break;
			} else {
				ans[++cnt] = q.top();
				q.pop();
			}
		}
	}
	if(flag) puts("NO");
	else {
		while(!q.empty()) {
			ans[++cnt] = q.top();
			q.pop();
		}
		puts("YES");
		for(int i = cnt; i >= 1; --i) {
			printf("%d ", ans[i]);
		}
	}
	return 0;
}