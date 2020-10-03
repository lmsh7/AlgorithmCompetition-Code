#include <bits/stdc++.h>
using namespace std;
string b;
inline bool judge(string a) {
	b = a;
	reverse(a.begin(), a.end());

	// cout << b <<endl;
	if(a == b) return true;
	else return false;
}

int main() {
	string a;
	cin >> a;
	if(!judge(a))
		printf("3\nL 2\nR 2\nR %d", 2 * a.length() - 1);
	else puts("0");
	return 0;
}