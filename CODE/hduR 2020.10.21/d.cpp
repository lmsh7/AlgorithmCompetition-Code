#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

const int N = 1000005;

int inversion[N], buc[N], trr[N];
int n, m;
// long long a[N], b[N];
map <long long, int> mp;

struct Node {
	int num;
	int rank;
	bool operator < (const Node x) const {
		return num < x.num;
	}
} a[N];

int lowbit(int x) {
	return x & (-x);
}

int query(int x) {
	int ans = 0;
	for(; x > 0; x -= lowbit(x)) {
		// cout << "A";
		// cout << x <<endl;
		ans += trr[x];
	}
	return ans;
}

void add(int x) {
	for(; x <= n; x += lowbit(x)) {
		// cout << x <<endl;
		trr[x] += 1;
	}
}


void getinversion() {
	for(int i = 1; i <= n; ++i) {
		inversion[i] = query(n) - query(a[i].num);
		add(a[i].num);
		// printf("inversion[%d] = %d\n", i, inversion[i]);
		inversion[i] += 1;
	}
}

// void swapp(int &x, int &y) {
// 	x ^= y;
// 	y ^= x;
// 	x ^= y;
// }

int main() {
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].num;
		a[i].rank = i;
		// for(int j = 1; j < i; ++j) {
		// 	if(a[j] > a[i]) {
		// 		inversion[i] ++;
		// 	}
		// }
		// inversion[i] ++;
		// O(n*2)
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		a[a[i].rank].num = i;
	}
	// sort(b + 1, b + n + 1);

	// for(int i =  1; i <= n; ++i) {
	// 	mp.insert(pair<long long, int>(b[i], i));
	
	// }
	// for(int i = 1; i <= n; ++i) {
	// 	a[i] = mp.find(a[i])->second;
	// 	// cout << a[i] <<endl;
	// }

	getinversion();//O(nlogn)
	//inversion + 1 = the turn of be good number 
	int mx = 1;
	for(int i = 1; i <= n; ++i) {
		buc[inversion[i]] ++;
		mx = max(mx, inversion[i]);		
	}
	for(int i = 2; i <= mx; ++i) {
		buc[i] = buc[i - 1] + buc[i];//the sum of good number in i-th turn = x
	}
	for(int i = 1; i <= mx; ++i) {
		buc[i] = n - buc[i];//the operation in i-th turn is n - x
	}
	int flag, x;
	for(int i = 1; i <= m; ++i) {
		cin >> flag >> x;
		if(flag == 2) {
			cout << buc[x] <<endl;
		} else {
			if(a[x].num > a[x + 1].num) {
				inversion[x + 1] --;
				buc[inversion[x + 1]] --;
				swap(a[x], a[x + 1]);
				swap(inversion[x], inversion[x + 1]);
			} else {
				buc[inversion[x]] ++;
				inversion[x] ++;
				swap(a[x], a[x + 1]);
				swap(inversion[x], inversion[x + 1]);
			}
		}
	}
	return 0;
}