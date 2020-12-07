#include <bits/stdc++.h>
using namespace std;

string r;
string b;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int R = 0;
		int B = 0;
		cin >> r;
		cin >> b;
		for(int i = 0; i < n; ++i) {
			if(r[i] > b[i]) R++;
			else if(r[i] < b[i]) B++;
		}
		if(R > B) puts("RED");
		else if(B > R) puts("BLUE");
		else puts("EQUAL");
	}
	return 0;
}