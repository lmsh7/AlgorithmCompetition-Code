#include <bits/stdc++.h>
using namespace std;
vector <string> vec;
string opt;
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> opt;
		if(opt[0] == 't') {
			string a;
			cin >> a;
			if(find(vec.begin(), vec.end(), a) == vec.end()) vec.push_back(a);
		} else if(opt[0] == 'l') {
			for(auto j : vec) {
				cout << j <<endl;
			}
		} else if(opt[0] == 'r' && opt[1] == 'e') {
			string a, b;
			cin >> a >> b;
			vector<string>::iterator result = find(vec.begin(), vec.end(), a);
			vector<string>::iterator result2 = find(vec.begin(), vec.end(), b);

			if(result != vec.end() && result2 == vec.end()) *(result) = b;
		} else {
			string a;
			cin >> a;
			vector<string>::iterator result = find(vec.begin(), vec.end(), a);
			if(result != vec.end()) vec.erase(result);
		}
	}
	return 0;
}
/*
9
ls
touch yyh
ls
touch yyhtql
rm yyhtql
rename yyh yyhtql
touch qwq
touch qwq
touch qwq
touch qwq
rename qwq 	hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
ls
*/