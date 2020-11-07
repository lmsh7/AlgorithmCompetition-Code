# hdu2020新生赛

过了6题, rank8.
12:00到12:40过了3题
14:55到16:00过了3题
中间的两个小时在纠结,神游,猜

### 1001 斐波那契阶乘

预处理

### 1002 爱搬砖的LaLa

没看

### 1003 这是一个签到题

真是签到题

### 1004 奖学金评定

普及了hdu绩点评定方法, 模拟

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const ll p = 998244353;
const int N = 5e4 + 10;

struct Course{
    double num, point, gpa1, gpa2;
    bool operator < (const Course &x) const {
        if(num == x.num) return point < x.point;
        else return num < x.num;
    }
} cou[N];

double gpa[N];
int k;

void calc(int du, double c, int n) {
    for(int i = 1; i <= n; ++i) {
        if(du >= cou[i].point) {
            double num1 = sqrt(cou[i].num) * 10.0;
            double num2;
            if(cou[i].num < 70) num2 = ((cou[i].num - 70.0) * 10.0) / 34.0 + 70;
            else num2 = cou[i].num;
            cou[i].gpa1 = min(5.0, (num1 - 45.0) * 0.10);
            cou[i].gpa2 = min(5.0, (num2 - 45.0) * 0.10);
            if(num1 < 60.0) {
                cou[i].gpa1 = 0;
            } 
            if(num2 < 60.0) {
                cou[i].gpa2 = 0;
            }             
            du -= cou[i].point;
        } else {
            cou[i].gpa1 = min(5.0, (cou[i].num - 45.0) * 0.10);
            cou[i].gpa2 = min(5.0, (cou[i].num - 45.0) * 0.10);
            if(cou[i].num < 60.0) {
                cou[i].gpa1 = 0;
                cou[i].gpa2 = 0;
            }
        }
    }
    double la = 0, lb = 0;
    double divd = 0;
    for(int i = 1; i <= n; ++i) {
        la += cou[i].gpa1 * cou[i].point;
        lb += cou[i].gpa2 * cou[i].point;
        divd += cou[i].point;
    }
    double Gpa1 = (la / divd) + c;
    double Gpa2 = (lb / divd) + c;
    int qwq1 = lower_bound(gpa + 1, gpa + 1 + k, Gpa1) - (gpa + 1);
    int qwq2 = lower_bound(gpa + 1, gpa + 1 + k, Gpa2) - (gpa + 1);
    printf("%d %d\n", k + 1 - qwq1, k + 1 - qwq2);
}

bool cmp(double a, double b) {
    return a < b;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, d;
        double c;
        scanf("%d %d %lf", &n, &d, &c);
        for(int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &cou[i].num, &cou[i].point);
        }
        sort(cou + 1, cou + n + 1);
        scanf("%d", &k);
        for(int i = 1; i <= k; ++i) {
            scanf("%lf", &gpa[i]);
        }
        sort(gpa + 1, gpa + k + 1, cmp);
        calc(d, c, n);
    } 
    return 0;
}
```

### 1005 斐波那契自动机

没看

### 1006 物理题

看了,不会

### 1007 万圣节的礼物

应当是暴力四个互质的大数

### 1008 NOWA爱抽卡

前缀和维护的dp

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const ll p = 998244353;
const int N = 5e4 + 10;

ll f[N], sum[N];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k, m;
        scanf("%d %d %d", &n, &k, &m);
        memset(f, 0, sizeof(f));
        f[0] = 1;
        sum[1] = 1;
        for(int i = 1; i <= n; ++i)  {
            f[i] += (sum[i] - sum[max(0, i - k)] + p) % p;
            f[i] %= p;

            for(int j = 1; j <= m; ++j) {
                if(i -  10 * j < 0) break;
                f[i] += f[i - 10 * j];
                f[i] %= p;
            }            
            sum[i + 1] = sum[i] + f[i];
            sum[i + 1] %= p;
        }
        cout <<f[n]<<endl;
    } 
    return 0;
}
```

### 1009 NoWA爱学习

贪心,倒序遍历,ddl靠后的先入优先队列, 优先队列里按照pub(发布时间)晚的排序,输出

- 注意: 存这一天有无ddl的vec记得多组数据清空

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int P = 998244353;
const int N = 1e4 + 10;

int n, h;
int t[N], pub[N], ddl[N];
int ans[N];
int ok[N];
vector <int> vec[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        int flag = 1;
        memset(ans, 0, sizeof(ans));
        memset(ok, 0, sizeof(ok));
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= k; ++i) vec[i].clear(); 
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &t[i], &pub[i], &ddl[i]);
            if(ddl[i] > k) ddl[i] = k;
            vec[ddl[i]].push_back(i);
        }
        priority_queue <pii, vector<pii>> q;
        for(int i = k; i >= 1; --i) {
            for(auto j: vec[i]) {
                q.push(make_pair(pub[j], j));
            }
        
            if(q.empty()) {
                continue;
            } else {
                int u = q.top().second;    
                if(i < pub[u]) {
                    flag = -1;
                    break;
                }
                t[u]--;
                if(t[u] == 0) {
                    ok[u] = 1;
                    q.pop();
                }
                ans[i] = u;                
            }

        }
        for(int i = 1; i <= n; ++i) if(!ok[i]) {
            flag = -1;
            break;
        }
        if(flag == -1) printf("-1\n");    
        else {
        
            for(int i = 1; i <= k - 1; ++i) {
                printf("%d ", ans[i]);
            }        
            printf("%d\n", ans[k]);    
        }

    }
    return 0;
}
```

### 1010 化学题

(是不是按照往年就能拿一个气球了qwq

暴力bfs即可

```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int P = 998244353;
const int N = 1e4 + 10;
const int M = 1e5 + 10;

int ecnt;
int n, m, qe;

struct Edge {
    int next, to;
} e[M];

int ans[N], head[N], vis[N], q[N];

inline void adde(int x, int y) {
    e[++ecnt].to = y;
    e[ecnt].next = head[x];
    head[x] = ecnt;
}

void bfs(int x, int t) {
    memset(vis, 0, sizeof(vis));
    int hed = 1;
    int tal = 1;
    q[hed] = x;
    ans[x] ++;
    while(hed <= tal) {
        int u = q[hed];
        hed++;
        if(vis[u] == t) break;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(v != x && !vis[v]) {
                vis[v] = vis[u] + 1;
                q[++tal] = v;
                ans[v] ++;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {    
        ecnt = 0;
        memset(ans, 0, sizeof(ans));
        memset(head, 0, sizeof(head));
        scanf("%d %d %d", &n, &m, &qe);
        for(int i = 1, la, lb; i <= m; ++i) {
            scanf("%d %d", &la, &lb);
            adde(la, lb);
            adde(lb, la);
        }
        for(int i = 1, la, lb; i <= qe; ++i) {
            scanf("%d %d", &la, &lb);
            bfs(la, lb);
        
        }
        for(int i = 1; i <= n - 1; ++i) 
            printf("%d ", ans[i]);
        printf("%d\n", ans[n]);    
    } 
    return 0;
}
```



