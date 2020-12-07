## A. Bovine Dilemma

感觉良好

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n; 
		cin >> n;
		map<int, int> mp;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			for(int j = 1; j < i; ++j) {
				int qwq = a[i] - a[j];
				mp[qwq] = 1;
			}
		}
		cout << mp.size() <<endl;
	}
	return 0;
}
```

## B. Last minute enhancements

当连续的数字组成的区间中数字数量多于区间长度时,答案在区间长度上$+1$

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; ++i) {
			int la;
			cin >> la;
			a[la] ++;
		}
		int ans = 0;
		int len = 0;
		int sum = 0;
		for(int i = 1; i <= 2 * n + 1; ++i) {
			if(a[i] == 0 &&	len) {
				if(sum > len) {
					ans += len + 1;
				} else ans += len;
				len = 0;
				sum = 0;
			}
			if(a[i]) {
				len ++;
				sum += a[i];
			}
		}
		cout << ans <<endl;
	}
}
```

## C. Canine poetry

困难qnq

### Code

```cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a;
		cin >> a;
		string aa = a;
		int last = 1;
		int ans = 0;
		if(a.length() == 1) {
			puts("0");
			continue;
		}			
		if(a.length() == 2) {
			if(a[0] == a[1]) puts("1");
			else puts("0");
			continue;
		}	
		for(int i = 1; i <= (a.length() - 1); ++i) {
			if((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2])) {
				ans ++;
				do {
					a[i] = a[i] + last;
					if(a[i] > 'z') a[i] = a[i] - 'z' - 1 + 'a';
				} while((i - 1 >= 0 && a[i] == a[i - 1]) || (i - 2 >= 0 && a[i] == a[i - 2])|| (i + 1 <= a.length() - 1 && a[i] == a[i + 1]) || (i + 2 <= a.length() - 1 && a[i] == a[i + 2]));
			}		
		}
		cout << ans <<endl;
	}
	return 0;
}
```

## D. 13th Labour of Heracles

先T后过

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair <long long, long long > Pii;

const int N = 1e5 + 10;

ll val[N];
ll du[N];

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <Pii> vec;
		// memset(du, 0, sizeof(du));
		for(int i = 1; i <= n; ++i) cin >> val[i];
		for(int i = 1; i <= n - 1; ++i) {
			int la, lb;
			cin >> la >> lb;
			du[la] ++;
			du[lb] ++;
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += val[i];
			du[i] -= 1;
			if(du[i] != 0)
				vec.emplace_back(make_pair(val[i], i));
		}
		cout << ans << " ";
		sort(vec.begin(), vec.end());
		int top = vec.size() - 1;
		for(int i = 2; i <= n - 1; ++i) {
			while(du[vec[top].second] <= 0 && top != 0) {
				top --;
			}
			du[vec[top].second] -= 1;
			ans += vec[top].first;
			cout << ans <<" ";
		}
		cout << endl;
	}
	return 0;
}
```

