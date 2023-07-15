#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, W;
    cin>>n>>W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    vector<vector<long long int>> dp(n+1, vector<long long int>(100005, 1e18));
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<100005; j++){
            //take the ith element or not
            dp[i][j] = dp[i-1][j];
            if(j>=v[i-1] && dp[i-1][j-v[i-1]]+w[i-1]<=W){
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i-1]]+w[i-1]);
            }
        }
    }
    int idx = 0;
    for(int i=0; i<100005; i++){
        if(dp[n][i]<1e18) idx = i;
    }
    cout<<idx<<endl;
    return 0;
}