#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull P = 1000000007;

ull a[1000004];
int ss[10005];

int main() {
	int k;
	vector<int> a;
	cin >> k;
	int lb;
	while(scanf("%d", &lb)) {
		if(lb == 0) break;
		a.push_back(lb);
	}
        int ans = 0;
        stack <int> q;
        for(auto i : a) {
          
            if(!q.empty()) {
                ans += (i ^ q.top());
                 printf("i = %d q = %d\n", i, q.top());
                ss[q.top()] ++;
                if(ss[q.top()] == k) {
                    q.pop();
                }            
            }

            q.push(i);
        }
               
   	cout << a.size() << endl;
	return 0;
}