#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 10;

int sum[N];
int mus[N]; 
int sum_0[N];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> vec;
    int summ = 0;
    for(int i = 0; i <= s.length() - 1; ++i) {

        if(i != 0 && s[i] == '0' && s[i - 1] == '1') {
            vec.emplace_back(summ);
            summ = 0;
        } else if(s[i] == '1') summ++;
        if(s[i] == '0' && vec.size()) {
            sum_0[vec.size()] ++;
        }        
        if(i == s.length() - 1 && s[i] == '1') {
            vec.emplace_back(summ);
        }
    }
    for(auto i : sum_0) {
        printf("%d\n", i);
    }
    if(vec.size() == 1) {
        puts("0");
        return 0;
    }
    // cout << vec.size() <<endl;
    int ans = N;
    for(int i = 0; i < vec.size(); ++i) {
        if(i > 0) sum[i] = sum[i - 1] + vec[i];
        else sum[i] = vec[i];
    }
    for(int i = vec.size() - 1; i >= 0; --i) {
        if(i == vec.size() - 1) mus[i] = vec[i];
        else mus[i] = vec[i] + mus[i + 1];
    }
    for(int i = 0; i < vec.size(); ++i) {
        if(i == 0) ans = min(ans, mus[i + 1]);
        if(i == vec.size() - 1) ans = min(ans, sum[i - 1]);
        else ans = min(sum[i - 1] + mus[i + 1], ans);
    }
    cout << ans << endl;
    return 0;
}
/*
24
000101010101000010101000
*/