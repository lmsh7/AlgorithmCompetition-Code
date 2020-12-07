#include <bits/stdc++.h>
using namespace std;

int U[15], R[15], L[15], D[15];
int las[15], ans[15];
char s[2005][2005];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= 9; ++i) {
			U[i] = n + 1;
			L[i] = n + 1;
			D[i] = 0;
			R[i] = 0;
			ans[i] = 0;
		}
		int x;
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s[i] + 1);
			for (int j = 1; j <= n; ++j) {
				x = s[i][j] - '0';
				U[x] = min(i, U[x]);
				D[x] = max(i, D[x]);
				L[x] = min(j, L[x]);
				R[x] = max(j, R[x]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= 9; ++j) las[j] = 0;
			for (int j = 1; j <= n; ++j) {
				x = s[i][j] - '0';
				if (las[x] == 0) las[x] = j;
				else {
					ans[x] = max(ans[x], (j - las[x]) * max(n - i, i - 1));
				}
				ans[x] = max(ans[x], max(n - j, j - 1) * max(D[x] - i, i - U[x]));
			}
		}
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= 9; ++j) las[j] = 0;
			for (int j = 1; j <= n; ++j) {
				x = s[j][i] - '0';//attention change to s[j][i]
				if (las[x] == 0) las[x] = j;
				else {
					ans[x] = max(ans[x], (j - las[x]) * max(n - i, i - 1));
				}
				ans[x] = max(ans[x], max(n - j, j - 1) * max(R[x] - i, i - L[x]));
			}
		}
		for (int i = 0; i <= 9; ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}