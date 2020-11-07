#include <bits/stdc++.h>
using namespace std;

int num[40][40][40];
int sum[40][40][40];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n * n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &num[(i - 1) / n][(i - 1) % n][j - 1]);
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				printf("%d ", num[i][j][k]);
			}	
			printf("  ");
		}	
		printf("\n");	
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1] ;
				sum[i][j][k] -= sum[i - 1][j - 1][k] + sum[i - 1][j][k - 1] + sum[i][j - 1][k - 1];
				sum[i][j][k] += num[i][j][k];
			}
		}		
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				printf("%d ", sum[i][j][k]);
			}	
			printf("  ");
		}	
		printf("\n");	
	}
	

	return 0;
}
