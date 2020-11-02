	  #include <bits/stdc++.h>
	#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
	using namespace std;
	typedef long long ll;
	typedef unsigned long long ull;

	const int lim = 100005;//因数最多到sqrt(q),质因数同理

	bool np[lim];
	int p[lim];
	int tot;
	int k[lim];
	int yinzi[lim];
	int phi[lim];

	void getphi() {
	    np[1] = phi[1] = 1;
	    for (int i = 2; i <= lim; ++i) {
	        if (!np[i]) p[++tot] = i, phi[i] = i - 1;
	        for (int j = 1; j <= tot && i * p[j] <= lim; ++j) {
	            np[i*p[j]] = 1;
	            if (i % p[j] == 0) {
	                phi[i*p[j]] = phi[i] * p[j];
	                break;
	            } else phi[i*p[j]] = phi[i] * (p[j] - 1);
	        }
	    }
	}

	int main() {
		int T;
		cin >> T;
		getphi();
		while (T--) {
			ll a, b;
			ll ans = 0;
			cin >> a >> b;
			if (a < b) cout << a << endl;
			else if (a % b != 0) cout << a << endl;
			else {
				for(int i = 1; i <= tot; ++i) {
					if(b % p[i] != 0) continue;
					ll res = 1;
					while(b % p[i] == 0) {
						b /= p[i];
						res *= p[i];
					}
					res /= p[i];
					ll a_res = a;
					while(a_res % p[i] == 0) {
						a_res /= p[i];
					}
					ans = max(ans, res * a_res);
				}
				if(b != 1) {
					ll res = 1;
					ll a_res = a;
					while(a_res % b == 0) {
						a_res /= b;
					}
					ans = max(ans, res * a_res);				
				}
				cout << ans<<endl;
			}
		}
		return 0;
	}