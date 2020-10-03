#include <bits/stdc++.h>
using namespace std;


const int N = 1005;

float t[N][N];

int main() {
	float n, x, v;
	cin >> n >> x >> v;
	float s = n * x;
	
	for(int i = 1; i <= n; ++i) {
		float tmp = 0;
		for(int j = 1; j <= n; ++j) {
			cin >> tmp;
			t[i][j] = s / (tmp - v);

		}
	}
	float ans;
	for(int i = 1; i <= n; ++i) {
		float tmp = 0;
		for(int j = 1; j <= n; ++j) {
			tmp += t[i][j];
		}
		tmp /= n;
		ans += tmp;
	}

	printf("%.2f", ans);
	return 0;
}