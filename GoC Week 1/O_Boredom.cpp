#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){
    int n, N = 100005;
    cin>>n;
    int x;
    vector<int> count(N, 0), dp(N, 0);
    for(int i=0; i<n; i++){
        cin>>x;
        count[x]++;
    }
    dp[1]=count[1];
    for(int i=2; i<N; i++){
        dp[i] = max(dp[i-1] , dp[i-2] + count[i]*i);
    }
    cout<<dp[N-1]<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
