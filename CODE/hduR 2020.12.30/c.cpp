#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 10;

int sta[M];
int top = 0;

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set <int> s;
	s.insert(0);
	s.insert(n + 1);

	for(int i = 1; i <= m; ++i) {
		char opt;
		int num;
		cin >> opt;
		if(opt == 'A') {
			cin >> num;
			sta[++top] = num;
			s.insert(num);
		} else if(opt == 'B') {
			s.erase(sta[top]);
			top --;
		} else {
			cin >> num;
			set<int>::iterator it, it_2;
			it = s.lower_bound(num) ;
			if(*it == num) {
				cout << "Imposssible" <<endl;
				continue;
			}
			it_2 = it;
			it --;
			cout << *it + 1<<" "<<*it_2 - 1 << endl;
		}
	}
	return 0;
}