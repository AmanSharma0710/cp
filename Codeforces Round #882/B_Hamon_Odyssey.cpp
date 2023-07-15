#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    int ans=v[0];
    for(int i=1; i<n; i++){
        ans=ans&v[i];
    }
    if(ans!=0){
        cout<<1<<endl;
        return;
    }
    int count=0;
    ans = -1;
    for(int i=0; i<n; i++){
        if(ans==-1) ans=v[i];
        else ans=ans&v[i];
        if(ans==0){
            count++;
            ans=-1;
        }
    }
    cout<<count<<endl;
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
