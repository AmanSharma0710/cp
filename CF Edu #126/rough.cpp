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


void solve(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    int maxx = 0;
    for(int i=0; i<n; i++){
        maxx = max(maxx, a[i]);
    }
    int ones=0, twos=0;
    for(int i=0; i<n; i++){
        ones+= (maxx-a[i])%2;
        twos+= (maxx-a[i])/2;
    }
    int diff = twos - ones;
    if(diff>0){
        twos -= diff/3;
        ones += (diff/3) * 2;
    }
    if(twos>ones){
        twos--;
        ones+=2;
    }
    if(ones>twos){
        cout<<ones+twos<<endl;
    }
    else{
        cout<<2*max(ones, twos)<<endl;
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
