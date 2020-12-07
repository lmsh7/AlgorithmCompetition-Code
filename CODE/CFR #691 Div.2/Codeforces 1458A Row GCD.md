> **题意**:题目中$m$次询问，每次询问$n$个数全部加上一个值后的$gcd$

### Solution

由$gcd(x,y,z)=gcd(x,y-x,z-y)$

可知当$n$个数同时加上同一个数时,因为后面的差值不变,只需要再计算「第一个数加上那个数」和「固定的差值的$gcd$」的$gcd$即可

### Code

```cpp

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
 
long long a[N];
long long b[N];
 
long long gcdd(long long a, long long b) {
	if(a == 0) return b;
	else return gcdd(b % a, a);
}
 
int main() {
	int n, m;
	cin >> n >> m;
 
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> b[i];
	if(n == 1) {
		for(int i = 1; i <= m; ++i) {
			printf("%lld ", a[1] + b[i]);
		}
		return 0;
	}
	sort(a + 1, a + n + 1);
	long long gcd = a[2] - a[1];
	for(int i = 2; i <= n; ++i) {
		gcd = gcdd(a[i] - a[i - 1], gcd);
	}
	for(int i = 1; i <= m; ++i) {
		printf("%lld ", gcdd(a[1] + b[i], gcd));
	}
}
/*
4 10
12 234 3456 121
1 2 3 4 5 6 7 8 9
 
5 4
1 25 121 169 16
1 2 7 23
*/
```

