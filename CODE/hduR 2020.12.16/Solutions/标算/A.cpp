#include<cstdio>
using namespace std;
const int maxn=10,maxm=10;
const int val[10]={1324,0,3412,3434,243,1234,121324,3,13241324,132434};

int te,n,m,now;bool pic[maxn+5][maxm+5];

inline char getdig() {char ch=getchar();while (ch!='0' && ch!='1') ch=getchar();return ch;}
int main(){
	for (scanf("%d",&te);te;te--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n+1;i++) for (int j=0;j<=m+1;j++) pic[i][j]=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				pic[i][j]=(getdig()=='1');
		now=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (pic[i][j]){
					if (pic[i-1][j] && pic[i][j+1] && !pic[i-1][j+1]) now=now*10+2;
					if (pic[i+1][j] && pic[i][j+1] && !pic[i+1][j+1]) now=now*10+1;
					if (pic[i-1][j] && pic[i][j-1] && !pic[i-1][j-1]) now=now*10+4;
					if (pic[i+1][j] && pic[i][j-1] && !pic[i+1][j-1]) now=now*10+3;
				}
		int i;for (i=0;i<=9;i++) if (now==val[i]) break;
		if (i<=9) {printf("%d\n",i);continue;}
		if (now==13214324) printf("8\n"); else printf("2\n");
	}
	return 0;
}