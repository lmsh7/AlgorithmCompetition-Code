#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = 2147483647;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		map <int, int> mp;
		for(int i = 1; i <= a; ++i) {
			int la;
			cin >> la;
			mp[la] = 1;
		} 
		int cnt = 0;
		for(int i = 1; i <= b; ++i) {
			int la;
			cin >> la;		
			if(mp[la] == 1) cnt ++;	
		}
		cout << cnt <<endl;
	}

	return 0;
}