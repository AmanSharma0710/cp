#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

void solve(){
    int n, k, d;
    cin>> n >> k >> d;
    vector<vector<int>> dp(2, vector<int>(n+1, 0));
    //dp[0][i] maintains the paths upto i which do not have any edge greater than d
    //dp[1][i] maintains the paths upto i which have at least 1 edge >=d
    //dp[1][i] = sum of dp[1][i-k] with k from 1 to k + sum of dp[0][i-k] where k goes from d to k
    //dp[0][i] = sum of dp[0][i-k] where k goes from 1 to d-1
    //answer is dp[1][n]
    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i-j<0){
                break;
            }
            if(j>=d){
                dp[1][i] = (dp[1][i] +  dp[0][i-j])%MOD;
            }
            if(j<d){
                dp[0][i] = (dp[0][i] + dp[0][i-j])%MOD;
            }
            dp[1][i] = (dp[1][i] + dp[1][i-j])%MOD;
        }
    }
    cout<<dp[1][n]<<endl;
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
