#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, w;
    cin>>n>>w;
    vii items(n);
    for(int i=0; i<n; i++){
        cin>>items[i].first>>items[i].second;
    }
    vector<vi> dp(n+1, vector<int>(w+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(j>=items[i-1].first){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].first] + items[i-1].second);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<=w; i++){
        ans=max(ans, dp[n][i]);
    }
    cout<<ans<<endl;
}