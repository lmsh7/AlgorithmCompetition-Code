#include<cstdio>
#include<cctype>
using namespace std;
typedef long long LL;
const int maxn=100000,maxt=maxn<<2,MOD=19260817;

int n,te,BA,a[maxn+5],pw[maxn+5],sum[maxn+5];
int len[maxt+5],val[maxt+5],tag[maxt+5];

#define EOLN(x) ((x)==10 || (x)==13 || (x)==EOF)
inline char readc(){
	static char buf[100000],*l=buf,*r=buf;
	return l==r && (r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<typename T> int readi(T &x){
	T tot=0;char ch=readc(),lst='+';
	while (!isdigit(ch)) {if (ch==EOF) return EOF;lst=ch;ch=readc();}
	while (isdigit(ch)) tot=(tot<<3)+(tot<<1)+(ch^48),ch=readc();
	lst=='-'?x=-tot:x=tot;return EOLN(ch);
}
void Build(int L,int R,int p=1){
	len[p]=R-L+1;tag[p]=-1;
	if (L==R) {val[p]=a[L];return;} int mid=L+(R-L>>1);
	Build(L,mid,p<<1);Build(mid+1,R,p<<1|1);
	val[p]=((LL)val[p<<1]*pw[len[p<<1|1]]+val[p<<1|1])%MOD;
}
inline void Addtag(int p,int k) {val[p]=(LL)sum[len[p]]*k%MOD;tag[p]=k;}
void Pushdown(int p) {if (~tag[p]) Addtag(p<<1,tag[p]),Addtag(p<<1|1,tag[p]),tag[p]=-1;}
void Insert(int L,int R,int k,int l=1,int r=n,int p=1){
	if (L==l && r==R) return Addtag(p,k);
	int mid=l+(r-l>>1);Pushdown(p);
	if (R<=mid) Insert(L,R,k,l,mid,p<<1); else if (L>mid) Insert(L,R,k,mid+1,r,p<<1|1);
	else Insert(L,mid,k,l,mid,p<<1),Insert(mid+1,R,k,mid+1,r,p<<1|1);
	val[p]=((LL)val[p<<1]*pw[len[p<<1|1]]+val[p<<1|1])%MOD;
}
int main(){
	readi(n);readi(BA);
	pw[0]=1;for (int i=1;i<=n;i++) pw[i]=(LL)pw[i-1]*BA%MOD;
	for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+pw[i-1])%MOD;
	for (int i=1;i<=n;i++) readi(a[i]);Build(1,n);
	for (readi(te);te;te--){
		int L,R,x;readi(L);readi(R);readi(x);
		Insert(L,R,x);printf("%d\n",val[1]);
	}
	return 0;
}