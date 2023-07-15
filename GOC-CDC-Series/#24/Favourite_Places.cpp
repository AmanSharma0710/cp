#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<double>> adj;
vector<vector<double>> dp;

double tsp(int mask, int pos){
    if (dp[pos][mask] != -1) return dp[pos][mask];
    if (mask == (1<<n)-1) return dp[pos][mask] = adj[pos][0];
    double ans = INT_MAX;
    for (int i=0; i<n; i++){
        if ((mask&(1<<i)) == 0){
            ans = min(ans, adj[pos][i] + tsp(mask|(1<<i), i));
        }
    }
    return dp[pos][mask] = ans;
}

void solve(){
    cin>>n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    adj.assign(n, vector<double>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            adj[i][j] = (a[i].first - a[j].first)*(a[i].first - a[j].first) + (a[i].second - a[j].second)*(a[i].second - a[j].second);
            adj[i][j] = sqrt(adj[i][j]);
        }
    }
    dp.assign(n, vector<double>(1<<n, -1));
    cout<<(int)tsp(1, 0)<<endl;
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
