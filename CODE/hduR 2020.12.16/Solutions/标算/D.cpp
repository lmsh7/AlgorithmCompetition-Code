#include<cstdio>
#include<unordered_map>
#define N 500007
#define mod 19260817
using namespace std;

int n, ans, f[N];

unordered_map<int, int> lst;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		f[i] = ((f[i - 1] << 1) + 2) % mod;
		if (lst.count(x)) f[i] = (f[i] - f[lst[x] - 1] - 1 + mod) % mod;
		ans = (ans + f[i]) % mod;
		lst[x] = i;
	}
	printf("%d\n", ans);
	return 0;
}