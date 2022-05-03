#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){
    int n;
    cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> dp(n, 0);
    map<int, int> prefixsum;
    for(int i=0; i<n; i++){
        if(i>0){
            dp[i]+=dp[i-1];
        }
        dp[i] += prefixsum[v[i]];
        prefixsum[v[i]] += (i+1);
    }
    int ans= 0;
    for(int i=0; i<n; i++){
        ans+= dp[i];
    }
    cout<<ans<<endl;
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
