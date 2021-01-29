## A. In-game Chat

~~奇怪的敏感词~~

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		int flag = 1;
		int num = 0;
		for(int i = a.length() - 1; i >= 0; --i) {
			if(flag && a[i] == ')') {
				num ++;
			} else {
				flag = 0;
			}
		}
		if(num > (n - num)) {
			puts("YES");
		} else puts("NO");
	}
}
```



## B. Fair Numbers

>**题意**:如果一个数能被其所有位上的数整除, 那么这个数是fair的. 给一个数, 求最小的比他大的fair数

卡了

然后我赌这个数离他自己肯定不远, 我赌对了

### Solution

因为$\text{LCM}(1, 2, 3, 4, 5, 6, 7, 8, 9)=2520$

所以直接从这个数一个一个向上加, 然后判断即可

由于$n \leq 10^3$所以复杂度可以满足需求

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

bool check(int x) {
	int w = 10;
	int dig = x % w;
	int num = x;
	while(x) {


		if(dig != 0 && num % dig != 0) return false;
		x /= 10;
		dig = x % w;
	}

	return true;
}

signed main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int num;
		cin >> num;
		while(!check(num)) {
			num++;
		}
		printf("%lld\n",num);
	}
	return 0;
}
```



## C. Peaceful Rooks

> **题意**:$n\times n$方阵中有$m$个**車(Rook)**,要求这$m$个**車**在每次移动后不能被其他**車**攻击到,求将所有**車**移动到主对角线上的最小步数

卡卡卡卡

没想到真是并查集

### Soluion

<img src="https://i.loli.net/2021/01/27/jpKSqwPR7iD3tVE.jpg" alt="QQ图片20210127190643.jpg" style="zoom:25%;" />

如果我们将一个**車**的坐标$(x, y )$用$x\to y$的边表示, 我们可以得到一张有自环, 环, 以及路线的图

示意图上很清楚地表明了为什么, 在这种情况下, 我们要移动其中一个**車**来让出位置

所以答案就是**車**数量减去自环(loop)数量, 加上环(cycle)数量

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

int fa[N];

int find_fa(int x) {
	return x == fa[x] ? fa[x] : fa[x] = find_fa(fa[x]);
}

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = m;
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		int lx, ly;
		cin >> lx >> ly;
		if(lx == ly) {
			ans --;
			continue;
		}
		if(find_fa(lx) == find_fa(ly)) {
			ans ++;
		} else {
			fa[fa[lx]] = ly;
		}
	}
	cout << ans <<endl;
	return;
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
```



## D. Grime Zoo

> **题意**: 给出一串中间有若干$?$的$01$序列, $?$可以为$0$或者$1$. 序列中$01$子序列(可以连续亦可以不连续)的出现次数会得到$x$个坏评论, 而序列中$10$子序列的出现次数会得到$y$个坏评论. 求安排$?$的值后能得到的最小的坏评论数目

### Solution

> 考虑相邻两个`?`之间的情况，假设他们之间有$ c_0 $个$0 $和 $c_1$个 $1$ ：
> - 第一个放 $0$ 第二个放 $1$ ，贡献是 $c_1x+c_0x+x+W=(c_0+c_1+1)x+W$
> - 第一个放 $1$ 第二个放 $0$ ，贡献是 $c_0y+c_1y+y+W=(c_0+c_1+1)y+W$
> 其中 $W$ 是他们之间和外部产生的贡献，显然是相同的。
> 也就是说，如果 $x<y$ ，那么相邻两个`?`一定不会放$ 10$ ，因为可以交换这两个`?`变成 $01$ ，答案更优，如果 $x≥y$ 则同理。

以上来自[ZigZagK](https://zigzagk.top/2020/12/21/CF1464B)的博文

补充一下接下来的操作, 如果$x < y$ 得到的`?`序列是$000011111$型的, 反之则为$1111111000000$型的, 我们需要的就是枚举$1$和$0$的分界线. 先假定`?`全为$1$, 通过预处理前缀后缀得到答案, 然后枚举分界线更新答案.

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

string s;
int pre[N][4], suf[N][4];


signed main() {
	cin >> s;
	int X, Y;
	cin >> X >> Y;
	int len = s.length() - 1;
	if(X >= Y) {
		swap(X, Y);
		for(int i = 0; i <= len; ++i) {
			if(s[i] != '?') {
				if(s[i] == '0') s[i] = '1';
				else s[i] = '0';
			}
		}
	}
	for(int i = 0; i <= len; ++i) {
		if(i != 0) {
			pre[i][0] = pre[i - 1][0];
			pre[i][1] = pre[i - 1][1];
			pre[i][2] = pre[i - 1][2];
		}
		if(s[i] == '0') {
			pre[i][0] ++;
		} else if(s[i] == '1') {
			pre[i][1] ++;
		} else {
			pre[i][2] ++;
		}
	}
	for(int i = len; i >= 0; --i) {
		if(i != len) {
			suf[i][0] = suf[i + 1][0];
			suf[i][1] = suf[i + 1][1];
			suf[i][2] = suf[i + 1][2];
		}
		if(s[i] == '0') {
			suf[i][0] ++;
		} else if(s[i] == '1') {
			suf[i][1] ++;
		} else {
			suf[i][2] ++;
		}
	}
	int now = 0;
	for(int i = 0; i <= len; ++i) {
		if(s[i] == '0') {
			now += (suf[i + 1][1] + suf[i + 1][2]) * X;
		} else {
			now += suf[i + 1][0] * Y;
		}
	}
	int ans = now;
	// cout << ans << endl;
	for(int i = 0; i <= len; ++i) {
		if(s[i] == '?') {
			now -= (pre[i][0] + pre[i][2] - 1) * X + suf[i + 1][0] * Y;
			now += pre[i][1] * Y + (suf[i + 1][1] + suf[i + 1][2]) * X;
			ans = min(ans, now);
			// cout << "minus"<<pre[i][0] * X + suf[i + 1][0] * Y<<endl;
			// cout <<"plus" <<pre[i][1] * Y + suf[i + 1][1] * X<<endl;
		}
	}
	cout << ans << endl;
	return 0;
}

```

