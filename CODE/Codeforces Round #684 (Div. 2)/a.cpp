/*
* @Author: LMSH7
* @Date:   2021-01-05 18:13:02
* @Last Modified by:   LMSH7
* @Last Modified time: 2021-01-11 21:10:13
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,c0, c1, h;
		cin >> n >> c0 >> c1 >> h;
		string s;
		cin >> s;
		int num0 = 0;
		int num1 = 0;

		for(int i = 0; i <= s.length() - 1; ++i) {
			if(s[i] == '1') num1 ++;
			else num0 ++;
		}
		if(h + c0 < c1) cout << num0 * c0 + (h + c0) * num1;
		else if(h + c1 < c0) cout << num1 * c1 +  (h + c1) * num0;
		else cout << num0 * c0 + num1 * c1;
		cout << endl;
	}

	return 0;
}