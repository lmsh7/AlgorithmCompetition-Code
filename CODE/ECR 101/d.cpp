#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n <= 32) {
			int cnt = 0;
			for(int i = n - 1; i >= 3; --i) {
				// if(i != 12)
				printf("%d %d\n", i, n);
				cnt ++;
			}	
			int a = n;
			while(a != 2) {cout << a << endl;
				a = ceil(1.0 * a / (1.0 * 2));
				printf("%d %d\n", n, 2);
				
				cnt ++;
			}
			printf("2 %d\n", n);
			cout << cnt + 1 <<endl;
		} else {
			int cnt = 0;
			for(int i = n - 1; i >= 3; --i) {
				if(i != 32) {
					// printf("%d %d\n", i, n);
					cnt ++;					
				}

			}	
			int a = n;
			while(a != 1) {
				// cout << a << endl;
				a = ceil(1.0 * a / (1.0 * 32));
				// printf("%d %d\n", n, 2);
				cnt ++;
			}

			cout << cnt + 5<<endl;
			for(int i = n - 1; i >= 3; --i) {
				if(i != 32) {
					printf("%d %d\n", i, n);
					cnt ++;					
				}

			}	
			a = n;
			while(a != 1) {
				a = ceil(1.0 * a / (1.0 * 32));
				printf("%d %d\n", n, 12);
				cnt ++;
			}
			for(int i = 1; i <= 5; ++i) {
				printf("32 2\n");
			}
		}
	}
}