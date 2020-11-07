#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

// int a[5005],b[5005];
int dp[5006][5005];
// short earl[5006][5005][2];
    string c, d;
    char a[5005];
    char b[5005];
    // string a, b;
int main(){
	// freopen("1.in", "r", stdin);
    int n, m;

    cin >> n >> m;
   	int ans = 0;
    cin >> c >> d;
    // puts("A");
    for(int i=0; i < n; i++){
    	a[i + 1] = c[i];
    }
	for(int i=0; i< m; i++) {
		b[i + 1] = d[i];
	}
	for(int i=1; i <= n; i++)
		for(int j=1; j<= m; j++){
			if(a[i]==b[j]){
				dp[i][j] = dp[i-1][j-1] + 2;
			}else{
				dp[i][j] = max(0, max( dp[i-1][j], dp[i][j-1] ) - 1);
			}
			ans = max(dp[i][j], ans);
		}
/*
题意：给 C 和 D 两个串

求 S(C,D) S(C,D) as 4⋅LCS(C,D)−|C|−|D|4⋅LCS(C,D)−|C|−|D|

 

if(c[i] == d[i]） 贡献+2；

else 贡献 - 1；
*/
	cout<<ans;
	return 0;
}