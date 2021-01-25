#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 10;
int prime[N];
int is_prime[N];
int p = 0;

void Eratosthenes(int n) {
  for (int i = 0; i <= n; ++i) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;  // prime[p]是i,后置自增运算代表当前素数数量
      for (int j = i * i; j <= n; j += i)  // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
                    // 的倍数开始，提高了运行速度
        is_prime[j] = 0;  //是i的倍数的均不是素数
    }
  }
}

signed main() {
	int t;
	cin >> t;
	Eratosthenes(1000005);
	while(t--) {
		int d;
		cin >> d;
		int u;
		for(int i = 0; i <= p; ++i) {
			if(prime[i] >= 1 + d) {
				u = i;
				// cout << u <<endl;
				break;
			}
		}
		int v;
		for(int i = u; i <= p; ++i) {
			if(prime[i] >= prime[u] + d) {
				v = i;
				break;
			}
		}
		cout << prime[v] * prime[u] <<endl;
	}
}