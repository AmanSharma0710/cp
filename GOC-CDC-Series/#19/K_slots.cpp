#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007

int n, k;
vector<int> v;
vector<int> mem;
int dp(int start,int mask){
    if(start==n)return 0;
    if(mem[mask]!=-1)return mem[mask];
    int ans=0;

    for(int bit=0;bit<2*k;bit++){
        if(((mask>>bit)&1)==0){
            ans=max(ans,(v[start]&(bit%k+1))+ dp(start+1,mask | 1ll<<bit));
        }
    }

    return mem[mask]=ans;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    v.resize(n);
    mem.resize(1ll<<2*k,-1);
    rep(i,0,n) cin>>v[i];
    cout<<dp(0,0)<<endl;
    return 0;
}
