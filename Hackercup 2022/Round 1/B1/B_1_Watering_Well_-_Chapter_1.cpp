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


void solve(){
    int n;
    cin>>n;
    vector<int> x1(n), y1(n);
    rep(i,0,n){
        cin>>x1[i]>>y1[i];
    }
    int m;
    cin>>m;
    vector<int> x2(m), y2(m);
    rep(i,0,m){
        cin>>x2[i]>>y2[i];
    }
    int ans = 0, temp=0;
    for(int i=0; i<n; i++){
        temp = (temp + x1[i]*x1[i])%MOD;
    }
    ans = (ans + (temp*m)%MOD)%MOD;
    temp = 0;
    for(int i=0; i<m; i++){
        temp = (temp + x2[i]*x2[i])%MOD;
    }
    ans = (ans + (temp*n)%MOD)%MOD;
    temp = 0;
    int sum1=0, sum2=0;
    for(int i=0; i<m; i++){
        sum2 = (sum2 + x2[i])%MOD;
    }
    for(int i=0; i<n; i++){
        temp = (temp + (sum2*x1[i])%MOD)%MOD;
    }
    ans = (ans - (temp*2)%MOD)%MOD;
    temp=0;
    //Repitition of above code for y1 and y2
    for(int i=0; i<n; i++){
        temp = (temp + y1[i]*y1[i])%MOD;
    }
    ans = (ans + (temp*m)%MOD)%MOD;
    temp = 0;
    for(int i=0; i<m; i++){
        temp = (temp + y2[i]*y2[i])%MOD;
    }
    ans = (ans + (temp*n)%MOD)%MOD;
    temp = 0;
    sum1=0, sum2=0;
    for(int i=0; i<m; i++){
        sum2 = (sum2 + y2[i])%MOD;
    }
    for(int i=0; i<n; i++){
        temp = (temp + (sum2*y1[i])%MOD)%MOD;
    }
    ans = (ans - (temp*2)%MOD)%MOD;
    ans += MOD;
    ans %= MOD;
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc=1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
