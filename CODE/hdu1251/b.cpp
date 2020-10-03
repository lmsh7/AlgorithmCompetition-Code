#include <bits/stdc++.h>
using namespace std;

struct Trie {
	int nex[2000002][26], cnt;
	int num[2000002];
	void insert(string &s) {
		int p = 0;
		for(int i = 0; i < s.length(); ++i) {
			int c = s[i] - 'a';
			if(!nex[p][c]) nex[p][c] = ++cnt;
			p = nex[p][c];
			num[p]++;
		}
	}
	int find(string &s) {
		int p = 0;
		for(int i = 0; i < s.length(); ++i) {
			int c = s[i] - 'a';
			if(!nex[p][c]) return 0;
			p = nex[p][c];
		}
		return num[p];
	}
} trie;

int main() {
	freopen("1.in", "r", stdin);

	string words;
	while(1) {
		getline(cin, words);
		if(words.length() == 0) break;
		trie.insert(words);
	}
	while(1) {
		string prefix;
		cin >> prefix;
		if(prefix.length() == 0) break;

		cout << trie.find(prefix) <<endl;
	}
	return 0;
}