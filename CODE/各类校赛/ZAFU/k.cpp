#include <bits/stdc++.h>
using namespace std;

int main() {
	string a;
	int n;
	int q;
	cin >> n >> q >> a;
	int cnt = 0;
	for(int i = 0; i <= n - 1; ++i) {
		if(i == 0) {
			if(a[i] == '1') cnt++;
		} else if(a[i] == '1' && a[i - 1] == '0') cnt++;
	}
	printf("%d\n", cnt);

	int ins;
	for(int i = 1; i <= q; ++i) {
		scanf("%d", &ins);
		ins--;
		if(a[ins] == '0' ) {
			if(n == 1) {
				cnt++;
			} else if(ins == 0) {
				if(a[ins + 1] == '0') cnt++;
			} else if(ins == n - 1) {
				if(a[ins - 1] == '0') cnt++;
			} else {
				if(a[ins - 1] == '1' && a[ins + 1] == '1') cnt--;
				else if(a[ins - 1] == '0' && a[ins + 1] == '0') cnt++;
			}
			a[ins] = '1';
		} else {
			if(n == 1) {
				cnt--;
			} else if(ins == 0) {
				if(a[ins + 1] == '0') cnt--;
			} else if(ins == n - 1) {
				if(a[ins - 1] == '0') cnt--;
			} else {
				if(a[ins - 1] == '1' && a[ins + 1] == '1') cnt++;
				else if(a[ins - 1] == '0' && a[ins + 1] == '0') cnt--;
			}
			a[ins] = '0';
		}
		printf("%d\n", cnt);
	}
	return 0;
}