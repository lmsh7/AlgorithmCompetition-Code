#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

string s;
int pre[N][4], suf[N][4];


signed main() {
	cin >> s;
	int X, Y;
	cin >> X >> Y;
	int len = s.length() - 1;
	if(X >= Y) {
		swap(X, Y);
		for(int i = 0; i <= len; ++i) {
			if(s[i] != '?') {
				if(s[i] == '0') s[i] = '1';
				else s[i] = '0';
			}
		}
	}
	for(int i = 0; i <= len; ++i) {
		if(i != 0) {
			pre[i][0] = pre[i - 1][0];
			pre[i][1] = pre[i - 1][1];
			pre[i][2] = pre[i - 1][2];
		}
		if(s[i] == '0') {
			pre[i][0] ++;
		} else if(s[i] == '1') {
			pre[i][1] ++;
		} else {
			pre[i][2] ++;
		}
	}
	for(int i = len; i >= 0; --i) {
		if(i != len) {
			suf[i][0] = suf[i + 1][0];
			suf[i][1] = suf[i + 1][1];
			suf[i][2] = suf[i + 1][2];
		}
		if(s[i] == '0') {
			suf[i][0] ++;
		} else if(s[i] == '1') {
			suf[i][1] ++;
		} else {
			suf[i][2] ++;
		}
	}
	int now = 0;
	for(int i = 0; i <= len; ++i) {
		if(s[i] == '0') {
			now += (suf[i + 1][1] + suf[i + 1][2]) * X;
		} else {
			now += suf[i + 1][0] * Y;
		}
	}
	int ans = now;
	// cout << ans << endl;
	for(int i = 0; i <= len; ++i) {
		if(s[i] == '?') {
			now -= (pre[i][0] + pre[i][2] - 1) * X + suf[i + 1][0] * Y;
			now += pre[i][1] * Y + (suf[i + 1][1] + suf[i + 1][2]) * X;
			ans = min(ans, now);
			// cout << "minus"<<pre[i][0] * X + suf[i + 1][0] * Y<<endl;
			// cout <<"plus" <<pre[i][1] * Y + suf[i + 1][1] * X<<endl;
		}
	}
	cout << ans << endl;
	return 0;
}
