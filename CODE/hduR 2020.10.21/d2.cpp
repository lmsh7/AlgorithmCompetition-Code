#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int a[N], inversion[N], buc[N], b[N], trr[N];
int n, m;
map <int, int> mp;

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
		inversion[i] = query(n) - query(a[i]);
		add(a[i]);
		// printf("inversion[%d] = %d\n", i, inversion[i]);
		inversion[i] += 1;
	}
}

int main() {
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
		// for(int j = 1; j < i; ++j) {
		// 	if(a[j] > a[i]) {
		// 		inversion[i] ++;
		// 	}
		// }
		// inversion[i] ++;
		// O(n*2)
	}

	sort(b + 1, b + n + 1);

	for(int i =  1; i <= n; ++i) {
		// printf("b[%d] = %d\n", i, b[i]);
		mp.insert(pair<int, int>(b[i], i));
	}
	for(int i = 1; i <= n; ++i) {
		map<int, int>::iterator it = mp.find(a[i]);
		if(it != mp.end()) a[i] = it->second;
		// cout << a[i] <<endl;
	}

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
			if(a[x] > a[x + 1]) {
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

/*
10 11
0 3 4 5 1 9 7 13 6 10
2 1
2 2
2 3
1 5
2 1
2 2
2 3
1 4
2 1
2 2
2 3
*/