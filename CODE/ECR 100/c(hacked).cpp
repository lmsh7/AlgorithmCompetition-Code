#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10;


int t[N];
int x[N]; 

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> t[i] >> x[i];
		}
		// int last_point_exist = -1;
		long long last_point_end_time = 0;
		long long last_point_begin_time = 0;
		long long last_point_target = 0;
		long long last_point_origin = 0;
		long long ans = 0;
		for(int i = 1; i <= n; ++i) {
			if(last_point_end_time <= t[i]) {
				// printf("%d\n", i);
				last_point_origin = last_point_target;
				last_point_target = x[i];
				last_point_end_time = abs(x[i] - last_point_origin) + t[i];
				last_point_begin_time = t[i];
				if(last_point_end_time <= t[i + 1] || i == n) ans++;
			} else {
				if(last_point_origin <= last_point_target) {
					if(x[i] <= last_point_target && x[i] >= last_point_origin) {
						long long now_point_time = last_point_begin_time +  x[i] - last_point_origin;
						if(now_point_time < t[i]) continue;
						if(now_point_time <= t[i + 1] || i == n) ans++;
					}
				} else {
					if(x[i] <= last_point_origin && x[i] >= last_point_target) {
						long long now_point_time = last_point_begin_time +  last_point_origin - x[i];
						if(now_point_time < t[i]) continue;
						if(now_point_time <= t[i + 1] || i == n) ans++;						
					}
				}
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}