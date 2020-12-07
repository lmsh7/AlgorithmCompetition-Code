#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll P = 1e9 + 7;
const int N = 1e5 + 10;

ll fa[N][7];
ll sum_a[7];


ll fb[N][7];
ll sum_b[7];
int main() {
	int n;
	string s;
	cin >> n >> s;
	ll ansA = 0;
	ll ansB = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'i') {
			ansA += sum_a[4];
			ansA %= P;
		}
		if(s[i] == 'z') {
			sum_a[4] += sum_a[3];
			sum_a[4] %= P;
		}
		if(s[i] == 'o') {
			sum_a[3] += sum_a[2];
			sum_a[3] %= P;
		}
		if(s[i] == 'a') {
			sum_a[2] += sum_a[1];
			sum_a[2] %= P;
		}
		if(s[i] == 'h') {
			sum_a[1] += 1;
			sum_a[1] %= P;
		}
	}
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'h') {
			sum_b[5] += sum_b[4];
			sum_b[5] %= P;

		}
		if(s[i] == 'z') {
			sum_b[4] += sum_b[3];
			sum_b[4] %= P;

		}
		if(s[i] == 'i') {
			sum_b[3] += sum_b[2];
			sum_b[3] %= P;


			ansB += sum_b[5];
			ansB %= P;
		}
		if(s[i] == 'e') {
			sum_b[2] += sum_b[1];
			sum_b[2] %= P;

		}
		if(s[i] == 'w') {
			sum_b[1] += 1;
			sum_b[1] %= P;
		}
	}
	cout << (ansA % P * ansB % P) % P <<endl;
	return 0;
}
/*
307751774483
*/