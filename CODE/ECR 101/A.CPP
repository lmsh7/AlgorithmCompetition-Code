#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a;
		cin >> a;
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		int flag = 1;
		if(a.length() % 2 == 1) {
			puts("NO");
			continue;
		}
		for(int i = 0; i <= a.length() - 1; ++i) {
			if(a[i] == '(') num1 ++;
			else if(a[i] == ')') num2 ++;
			else num3 ++;
			if(num1 - num2 < 0) {
				num3 -= (num2 - num1);
				num1 = num2;
				if(num3 < 0) flag = -1;
			}
		}
		// if(flag == -1) {
		// 	puts("NO");
		// 	continue;
		// } else if(num3 % 2 == 1) {
		// 	puts("NO");
		// 	continue;
		// }
		// // cout << num3 <<endl;
		num1 = num2 = num3 = 0;
		for(int i = a.length() - 1; i >= 0; --i) {   
			if(a[i] == '(') num1 ++;
			else if(a[i] == ')') num2 ++;
			else num3 ++;
			if(num2 - num1 < 0) {
				num3 -= (num1 - num2);
				num2 = num1;
				if(num3 < 0) flag = -1;
			}
		}
		// cout << num3 <<endl;
		if(flag == -1) puts("NO");
		else puts("YES");
	}
	return 0;
}