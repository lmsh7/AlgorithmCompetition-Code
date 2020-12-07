## A. Buy the String

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,c0, c1, h;
		cin >> n >> c0 >> c1 >> h;
		string s;
		cin >> s;
		int num0 = 0;
		int num1 = 0;

		for(int i = 0; i <= s.length() - 1; ++i) {
			if(s[i] == '1') num1 ++;
			else num0 ++;
		}
		if(h + c0 < c1) cout << num0 * c0 + (h + c0) * num1;
		else if(h + c1 < c0) cout << num1 * c1 +  (h + c1) * num0;
		else cout << num0 * c0 + num1 * c1;
		cout << endl;
	}
	return 0;
}
```

## B. Sum of Medians

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int m = ceil(n / 2.0);
		for(int i = 1; i <= n * k; ++i) {
			cin >> a[i];
		}
		int num = 0;
		long long ans = 0;
		for(int i = n * k - (n - m); i >= 1; i -= (n - m)) {
			ans += a[i];
			num ++;
			i--;
			if(num == k) break;
		}
		cout << ans << endl;
	}
	return 0;
}
```

## C. Binary Table 

> **题意**:给定一个$ n\times m$ 的 $01$ 矩阵，每次操作可以将某个$ 2\times2$的矩阵内的 $3$个数取反，请在 $3\times n\times m$步内将矩阵变为全$ 0$。

### Solution

C2在C1的基础上进行了谜之优化,所以放在一块了

我的做法是从左到右从上到下对每个$2\times2$的矩阵进行操作

根据矩阵内$1$的数量分类,对于每种数量的情况进行操作,其实就是大模拟.

值得一提的优化是当从左到右,遍历矩阵右下顶点**快要**到边界时,由于这时正在操作的矩阵和下一个矩阵是重叠关系, 所以可以只考虑将$2\times 2$矩阵内左一列全变为$1$的情况

只有这个还不足以过$C2$,所以又同理将从上到下的**快到**边界的情况进行了优化.

因为懒惰, 所以细节并没有给出, 可以参考这篇博客https://www.cnblogs.com/luoyugongxi/p/14002155.html

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;


const int N = 105;

int n, m;

char a[N][N];

struct Node {
	int x1, y1, x2, y2, x3, y3;
};

vector <Node> vec;


int _count(int x, int y) {
	int num = 0;
	for(int i = x; i >= x - 1; --i)
		for(int j = y ; j >= y - 1; --j) {
			num += a[i][j] - '0';
		}
	return num;
}

void solve(int num, int x, int y) {
	if(num == 0) {
		return;
	} else if(num == 3) {
		int lx[3];
		int ly[3];
		int cnt = 0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '1') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				}
			}
		vec.emplace_back(Node{lx[0], ly[0], lx[1], ly[1], lx[2], ly[2]});
		a[lx[0]][ly[0]] = '0';
		a[lx[1]][ly[1]] = '0';
		a[lx[2]][ly[2]] = '0';
	} else if(num == 2) {
		int lx[3];
		int ly[3];
		int cnt = 0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '1') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				}
			}
		if(lx[0] != lx[1] && ly[0] != ly[1]) {
			int lx0[2];
			int ly0[2];
			int cnt0 = 0;
			for(int i = x; i >= x - 1; --i)
				for(int j = y ; j >= y - 1; --j) {
					if(a[i][j] == '0') {
						lx0[cnt0] = i;
						ly0[cnt0] = j;
						++cnt0;
					}
				}
			vec.emplace_back(Node{lx0[0], ly0[0], lx0[1], ly0[1], lx[0], ly[0]});
			a[lx0[0]][ly0[0]] = '1';
			a[lx0[1]][ly0[1]] = '1';
			a[lx[0]][ly[0]] = '0';
			solve(3, x, y);
			return;
		} else {	
			int lx0[3];
			int ly0[3];
			int	cnt0 = 0;
			for(int i = x; i >= x - 1; --i)
				for(int j = y ; j >= y - 1; --j) {
					if(a[i][j] == '0') {
						lx0[cnt0] = i;
						ly0[cnt0] = j;
						++cnt0;
					}
				}
			vec.emplace_back(Node{lx0[0], ly0[0], lx0[1], ly0[1], lx[0], ly[0]});
			a[lx0[0]][ly0[0]] = '1';
			a[lx0[1]][ly0[1]] = '1';
			a[lx[0]][ly[0]] = '0';
			solve(3, x, y);
		}
	} else if(num == 1) {
		int lx[3];
		int ly[3];
		int cnt = 0;
		int lx0;
		int ly0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '0') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				} else if(a[i][j] == '1') {
					lx0 = i;
					ly0 = j;
				}
			}
		if(lx[0] != lx[1] && ly[0] != ly[1]) {
			lx[1] = lx[2];
			ly[1] = ly[2];
		}
		vec.emplace_back(Node{lx[0], ly[0], lx[1], ly[1], lx0, ly0});
		a[lx[0]][ly[0]] = '1';
		a[lx[1]][ly[1]] = '1';
		a[lx0][ly0] = '0';
		solve(2, x, y);
	} else if(num == 4) {
		int lx[5];
		int ly[5];
		int cnt = 0;
		for(int i = x; i >= x - 1; --i)
			for(int j = y ; j >= y - 1; --j) {
				if(a[i][j] == '1') {
					lx[cnt] = i;
					ly[cnt] = j;
					++cnt;
				}
			}
		vec.emplace_back(Node{lx[0], ly[0], lx[1], ly[1], lx[2], ly[2]});
		a[lx[0]][ly[0]] = '0';
		a[lx[1]][ly[1]] = '0';
		a[lx[2]][ly[2]] = '0';
		solve(1, x, y);
	} else if(num == -1) {
		if(a[x - 1][y - 1] == '0' && a[x][y - 1] == '0') return;
		else if(a[x - 1][y - 1] == '1' && a[x][y - 1] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x, y - 1, x, y});
			a[x - 1][y - 1] = '0';
			a[x][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';
		} else if(a[x - 1][y - 1] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x - 1, y, x, y});
			a[x - 1][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x - 1][y] == '1') a[x - 1][y] = '0';
			else a[x - 1][y] = '1';		
		} else if(a[x][y - 1] == '1') {
			vec.emplace_back(Node{x, y - 1, x - 1, y, x, y});
			a[x][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x - 1][y] == '1') a[x - 1][y] = '0';
			else a[x - 1][y] = '1';	
		}
	} else if(num == -2) {
		if(a[x - 1][y - 1] == '0' && a[x - 1][y] == '0') return;
		else if(a[x - 1][y - 1] == '1' && a[x - 1][y] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x - 1, y, x, y});
			a[x - 1][y - 1] = '0';
			a[x - 1][y] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';
		} else if(a[x - 1][y - 1] == '1') {
			vec.emplace_back(Node{x - 1, y - 1, x, y - 1, x, y});
			a[x - 1][y - 1] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x][y - 1] == '1') a[x][y - 1] = '0';
			else a[x][y - 1] = '1';		
		} else if(a[x - 1][y] == '1') {
			vec.emplace_back(Node{x - 1, y, x, y - 1, x, y});
			a[x - 1][y] = '0';
			if(a[x][y] == '1') a[x][y] = '0';
			else a[x][y] = '1';			
			if(a[x][y - 1] == '1') a[x][y - 1] = '0';
			else a[x][y - 1] = '1';	
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vec.clear();
		for(int i = 1; i <= n; ++i) 
			scanf("%s", a[i] + 1);
		for(int i = 2; i <= n; i + 2 > n ? i += 1 : i += 2) {
			for(int j = 2; j <= m; j + 2 > m ? j += 1 : j += 2) {
				
				if(j + 2 > m && j != m) solve(-1, i, j);
				else if(i + 2 > n && i != n) solve(-2, i, j);
				else solve(_count(i, j), i, j);
			}
		}
		cout << vec.size() <<endl;
		if(vec.size() == 0) continue;
		for(int i = 0; i <= vec.size() - 1; ++i) {
			printf("%d %d %d %d %d %d\n", vec[i].x1, vec[i].y1, vec[i].x2, vec[i].y2, vec[i].x3, vec[i].y3);
		}

	}
}
```

