#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

string s[N];

int n;
int ans;
string now[N];
int top;

void dfs(int x) {
	// cout << x << endl;
	if(x == n + 1) {
		ans ++;
		// for(int i = 1; i <= top; ++i) {
		// 	cout << now[i] <<endl;
		// } 
		// cout <<endl;
		return;
	}
	dfs(x + 1);
	for(int i = 1; i <= top; ++i) {
		if(now[i].length() > s[x].length()) {
			if(now[i].find(s[x]) == 0) return;
		} else {
			if(s[x].find(now[i]) == 0) return;
		}
	}
	now[++top] = s[x];
	dfs(x + 1);
	top--;
	return;
}

int main() {
	// int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	dfs(1);
	// map <string, int> mp;
	cout << ans - 1 <<endl;
	return 0;
}