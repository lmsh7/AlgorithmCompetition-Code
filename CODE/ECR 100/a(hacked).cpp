#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;



int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int cha = a + b + c - 3 * min({a, b, c});
		int num = cha / 6;
		if(min({a, b, c}) - num < 0) puts("NO");
		else {
			int yu = (min({a, b, c}) - num) * 3;
			if(yu == 0) puts("YES");
			else {
				if(yu == 3) puts("NO");
				else if((cha % 6) % 3 != 0){
					puts("NO");
				} else if(cha % 6 == 3) {
					if(((yu + 3) / 3) % 3 == 0) puts("YES");
					else puts("NO");
				} else if(cha % 6 == 0) {
					if((yu / 3) % 3 == 0) puts("YES");
					else puts("NO");
				}
			}
		}
	}
	return 0;
}