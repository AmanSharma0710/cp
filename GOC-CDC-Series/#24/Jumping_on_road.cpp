#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    vector<int> dp(n+1, 0);
    multiset<int> s;
    s.insert(0);
    for(int i=0; i<n; i++){
        int x = *s.begin();
        dp[i+1] = x + a[i];
        s.insert(dp[i+1]);
        if(i-k+1 >= 0) s.erase(s.find(dp[i-k+1]));
    }
    cout<<dp[n]<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
