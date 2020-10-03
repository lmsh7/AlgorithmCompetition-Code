#include <bits/stdc++.h>
using namespace std;

int main() {
	string initial;
	while(1) {
		getline(cin, initial);
		if(initial[0] == '#') break;
		stringstream newInput(initial);
		string word;
		map <string, int> mp;
		int ans = 0;
		while(newInput >> word) {
			if(mp.find(word) == mp.end()) {
				mp.insert(pair<string, int>(word, 1));
				ans++;
			}
		}		
		cout << ans <<endl;
	}

}