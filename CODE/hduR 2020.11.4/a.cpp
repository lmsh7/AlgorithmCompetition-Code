#include <bits/stdc++.h>//合影 set 贪心
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;

const int Maxn = 1e5 + 10;


struct Node {
	int a, h;
} A[Maxn], B[Maxn];

multiset <int> s1[Maxn], s2[Maxn], S;

void work() {
	int n;
	cin >> n;
	vector <int> Vec1, Vec2;
	rep(i, 1, n) {
		scanf("%d", &B[i].a);
		Vec1.emplace_back(B[i].a);
	}
	rep(i, 1, n) scanf("%d", &B[i].h);
	rep(i, 1, n) { 
		scanf("%d", &A[i].a);
		Vec2.emplace_back(A[i].a);
	}
	//离散化
	rep(i, 1, n) scanf("%d", &A[i].h);
	sort(begin(Vec1),end(Vec1));
	sort(begin(Vec2),end(Vec2));
	Vec1.erase(unique(begin(Vec1), end(Vec1)), end(Vec1));
	Vec2.erase(unique(begin(Vec2), end(Vec2)), end(Vec2));
	rep(i, 1, n) B[i].a = lower_bound(begin(Vec1), end(Vec1), B[i].a) - begin(Vec1) + 1;
	rep(i, 1, n) A[i].a = lower_bound(begin(Vec2), end(Vec2), A[i].a) - begin(Vec2) + 1;
	//离散化
	rep(i, 1, n) s1[B[i].a].insert(B[i].h);
	rep(i, 1, n) s2[A[i].a].insert(A[i].h);
		
	int j = 1;//后排的"块"号
	rep(i, 1, Vec2.size()) {
		while(S.size() < s2[i].size()) {
			for(auto k : s1[j]) {
				S.insert(k);
			}
			++j;
		}
		for(auto k : s2[i]) {
			multiset<int>::iterator find_in_B = S.upper_bound(k);//注意不要用upper_bound(begin(S), end(S), k), 效率和set内置的相比很慢
			if(find_in_B == S.end()) {
				rep(z, 1, Vec1.size()) s1[z].clear();
				rep(z, 1, Vec2.size()) s2[z].clear();
				S.clear();
				puts("No");
				return;
			}
			S.erase(find_in_B);
		}
	}
	rep(i, 1, Vec1.size()) s1[i].clear();
	rep(i, 1, Vec2.size()) s2[i].clear();
	S.clear();
	puts("Yes");
	return;
}

int main() {
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}