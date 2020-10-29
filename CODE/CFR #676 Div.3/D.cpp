#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long x, y, c1, c2, c3, c4, c5, c6;
		cin >> y >> x >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
		long long xm1, ym1, xp1, yp1, xym1, xyp1;
		xp1 = min(c2, c1 + c3);
		yp1 = min(c6, c1 + c5);
		xyp1 = min({c1, c2 + c6, xp1 + yp1});

		xm1 = min(c5, c4 + c6);
		ym1 = min(c3, c4 + c2);
		xym1 = min({c4, c5 + c3, xm1 + ym1});
		// printf("xp1 = %lld , yp1 = %lld, xyp1 =%lld , xm1 = %lld, ym1 = %lld, xym1 = %lld\n",xp1, yp1, xyp1, xm1, ym1, xym1);
		unsigned long long  ans = 0;
		if(x * y > 0) {
			long long q = min(abs(x), abs(y));
			if(x < 0) {
				x += q;
				y += q;
				ans += q * xym1;
			} else { 
				x -= q;
				y -= q;
				ans += q *  xyp1;
			}
			if(x != 0) {
				if(x < 0) {
					ans += xm1 * abs(x);
					x = 0;
				} else {
					ans += xp1 * x;
					x = 0;
				}
			} else {
				if(y < 0) {
					ans += ym1 * abs(y);
					y = 0;
				} else {
					ans += yp1 * y;
					y = 0;
				}
			}
		} else {
			if(y < 0) {
				ans += ym1 * abs(y);
				y = 0;
						// cout << ans << endl;


			} else {
				ans += yp1 * y;
				y = 0;
			}
			if(x < 0) {
				ans += xm1 * abs(x);
				x = 0;
			} else {
				ans += xp1 * x;
				x = 0;
						// cout << ans << endl;

			}			

		}
		cout << ans << endl;

	}
	return 0;
}