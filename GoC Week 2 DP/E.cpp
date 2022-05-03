#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define N 100001
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, w;
    cin>>n>>w;
    vii items(n);
    for(int i=0; i<n; i++){
        cin>>items[i].first>>items[i].second;
    }
    vector<vi> dp(n+1, vector<int>(N, INT_MAX));
    // dp[i][j]  has minimum weight when i elements have been considered and with quality j
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<N; j++){
            if(j>=items[i-1].second){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-items[i-1].second] + items[i-1].first);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans;
    for(int i=N-1; i>=0; i--){
        if(dp[n][i]<=w){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}