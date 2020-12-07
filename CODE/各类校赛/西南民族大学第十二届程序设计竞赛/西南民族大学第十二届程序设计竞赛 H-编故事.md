> **题意**:要从每组五个人中选一个人，使得所有被选中的人的步子差尽可能的小。

### Solution

将所有人的步子大小排序, 尺取法,贪心

「反复的**推进**区间开头或者结尾，求满足条件的**最小区间**的方法称为尺取法」

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e5 + 10;

int vis[N];

int main() {
    int n, k;
    cin >>n >> k;
    int la;
    vector <pii> vec;
    for(int i = 1; i <= n; ++i) {
        for(int _ = 1; _ <= 5; ++_) {
            int la;
            cin >> la;
            vec.emplace_back(la,i);
        }
    }
    sort(vec.begin(), vec.end());
    int l_point = 0;
    int num = 0;
    int ans = k + 1;
    for(int i = 0; i <= n * 5 - 1; ++i) {
        if(vis[vec[i].second] == 0) {
            num ++;
        }
        vis[vec[i].second]++;
        while(num == n) {
            ans = min(ans, vec[i].first - vec[l_point].first);
            vis[vec[l_point].second]--;
            if(vis[vec[l_point].second] == 0) num--;
            l_point++;
        }
    }
    
    if(ans > k) puts("-1");
    else cout << ans <<endl;
    return 0;

}
```

 ~~直角引号真好看~~