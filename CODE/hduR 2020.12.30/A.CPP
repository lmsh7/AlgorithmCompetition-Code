#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

double map[305][305];
// double ans[111];
double eps=1e-7;

int main(){
	int n, m;
	double div;
	
	cin>>n >> m;
	int ans = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%lf",&map[j][i]);

	 // for(int q = 1; q <= m; ++q) {
	 // 	for(int qq = 1; qq <= n; ++qq) {
	 // 		printf("%lf ", map[q][qq]);
		// 	}
		// 	puts("");
		// }
	if(m < n) {
		
		for(int i = m + 1; i <= n; ++i)
			for(int j = 1; j <=n ; ++j) {
				map[i][j] = 0;
			}
		m = n;
	}
	int last = 1;
	for(int i = 1; i <= n; i++){
		
		int r = last;
		
        for(int j = i + 1; j <= m; j++)
            if(fabs(map[r][i])<fabs(map[j][i]))
                r=j;
    	
		
		if( fabs(map[r][i]) < eps || isnan(map[r][i]) || isinf(map[r][i])){
            // printf("No Solution");
            ans ++;
            continue;
            // return 0;?
        }
		if(r != last) swap(map[last], map[r]);
		// printf("r = %d i = %d\n", r, i);
		div = map[last][i];
		// cout << div <<endl;
		for(int j = i; j <= n; j++)
			map[last][j] = map[last][j] / div;
			
		for(int j = last + 1; j <= m; j++){
			div = map[j][i];
			for(int k = i; k <= n; k++){
				map[j][k] = map[j][k] - ( map[last][k] * div);
			}
		}

	 // for(int q = 1; q <= m; ++q) {
	 // 	for(int qq = 1; qq <= n; ++qq) {
	 // 		printf("%lf ", map[q][qq]);
		// 	}
		// 	puts("");
		// }
		last ++;
	}
	cout << ans <<endl;
	return 0;
}
/*
5 4
1 13 5 14
2 3 3 3
2 2 0 2
3 4 3 4
3 4 3 4
*/

/*
4 3
1 1 2
1 1 2
2 2 3
2 1 2
*/