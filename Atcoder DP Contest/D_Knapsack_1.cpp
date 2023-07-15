#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, W;
    cin>>n>>W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    vector<vector<long long int>> dp(n+1, vector<long long int>(W+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            //either take the ith element or dont
            dp[i][j] = dp[i-1][j]; //not taking the ith element
            if(j-w[i-1]>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
            }
        }
    }
    long long int ans = 0;
    for(int i=0; i<=W; i++){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}