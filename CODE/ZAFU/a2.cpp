#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int mo=1e9+7;
const int N=1e7+10;
ll f[N];
int fsp(int x,int y)
{
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans%mo;
    if (y&1) ans=ans*x%mo;
    return ans;
}
int main()
{
    freopen("a2.out", "w", stdout);
    ios::sync_with_stdio(false);
    // int T;
    // cin>>T;
    ll ans=1;
    f[0]=1;
    rep(i,1,101840)
    {
        ans=ans*(ans+1)%mo;
        f[i]=ans;
        cout << f[i] <<endl;
    }
    // while (T--)
    // {
    //     int a,b;
    //     cin>>a>>b;
    //     if (a<b) swap(a,b);
    //     if (a>6773) a=(a-6773)%(51840-6773)+6773;
    //     if (b>6773) b=(b-6773)%(51840-6773)+6773;
    //     ll now=f[a]*fsp(f[b],mo-2)%mo;
    //     cout<<now<<endl;
    // }
    return 0;
}