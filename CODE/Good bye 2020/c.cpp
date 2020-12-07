#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a;
		cin >> a;
		string aa = a;
		int last = 1;
		int ans = 0;
		if(a.length() == 1) {
			puts("0");
			continue;
		}			
		if(a.length() == 2) {
			if(a[0] == a[1]) puts("1");
			else puts("0");
			continue;
		}	
		for(int i = 1; i <= (a.length() - 1); ++i) {
			if((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2])) {
				ans ++;
				do {
		// 			// cout << a[i] <<endl;
		// 			// cout<<i <<" " << a <<endl;
					a[i] = a[i] + last;
					if(a[i] > 'z') a[i] = a[i] - 'z' - 1 + 'a';
				} while((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2])|| (i + 1 <= a.length() - 1 && a[i] == a[i + 1]) || (i + 2 <= a.length() - 1 && a[i] == a[i + 2]));
			}
				
		}
		// std::vector<pair<int, int>> vec;
		// for(int i = 0; i <= (a.length() - 1); ++i) {
		// 		int tmp = 0;
		// 		if((i - 1 >= 0 && a[i] == a[i - 1])) tmp ++;
		// 		if((i - 2 >= 0 && a[i] == a[i - 2])) tmp ++;
		// 		if((i + 1 <= a.length() - 1 &&a[i] == a[i + 1])) tmp ++;
		// 		if((i + 2 <= a.length() - 1 && a[i] == a[i + 2])) tmp ++;
		// 		if(tmp) vec.emplace_back(tmp, i);

		// }
		// sort(vec.begin(),vec.end());
		// for(int j = vec.size() - 1; j >= 0; --j) {
		// 	int i = vec[j].second;
		// 	// cout << j << endl;
		// 	if((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2]) || (i + 1 <= a.length() - 1 &&a[i] == a[i + 1]) || (i + 2 <= a.length() - 1 && a[i] == a[i + 2])) {
		// 		ans ++;
		// 		do {
		// 			// cout << a[i] <<endl;
		// 			// cout<<i <<" " << a <<endl;
		// 			a[i] = a[i] + last;
		// 			if(a[i] > 'z') a[i] = a[i] - 'z' - 1 + 'a';
		// 		} while((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2]) || (i + 1 <= a.length() - 1 &&a[i] == a[i + 1]) || (i + 2 <= a.length() - 1 && a[i] == a[i + 2]));				
		// 	}
		// }
		// for(int i = 0; i <= (a.length() - 1); ++i) {
		// 	if(a[i] != aa[i]) {
		// 		if((i - 1 >= 0 && aa[i] == a[i - 1]) || (i - 2 >= 0 && aa[i] == a[i - 2]) || (i + 1 <= a.length() - 1 && aa[i] == a[i + 1]) || (i + 2 <= a.length() - 1 && aa[i] == a[i + 2])) {
		// 			continue;
		// 		} else {
		// 			// cout << a <<endl;
		// 			a[i] = aa[i];
		// 			ans--;
		// 		}
		// 	}
		// }
		// cout << a <<endl;
		cout << ans <<endl;
		// 	}
		// }
	}
	return 0;
}