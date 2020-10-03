#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("1.in", "r", stdin);
	map <string, int> mp;
	while(1) {
		string tmp;
		getline(cin, tmp);
		if(tmp.length() == 0) break;
		string qianzhui = "";
		for(int i = 0; i < tmp.length(); ++i) {
			qianzhui += tmp[i];
			if(mp.find(qianzhui) == mp.end()) {
				mp.insert(pair<string, int> (qianzhui, 1));
			} else {
				mp.find(qianzhui)->second ++;
			}
			// cout << mp.find(qianzhui)->second << endl;
		}
	}
	// string fuc_tmp;
	// cin >> fuc_tmp;
	while(1) {
		string tmp;
		cin >> tmp;
		// cout <<tmp<< endl;
		if(tmp.length() == 0) break;
		// cout << "fuck2" << endl;
		if(mp.find(tmp) == mp.end()) {
			cout << "0" <<endl;
		}else cout << mp.find(tmp)->second << endl;
	}
}