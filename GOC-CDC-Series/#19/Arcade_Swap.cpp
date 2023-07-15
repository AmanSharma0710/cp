#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n, m;
vector<vector<int>>dp, dp1;
vector<int>l, r;
vector<int>ans;

int dfs(int i, int sum){
    if(i==n){
        if(sum==m) return 1;
        return 0;
    }
    if(sum>m){
        return 0;
    }
    if(dp1[i][sum]!=-1){
        return dp1[i][sum];
    }
    if(dp[i+1][sum+l[i]]==1){
        ans.push_back(0);
        if(dfs(i+1, sum+l[i])==1){
            return dp1[i][sum]=1;
        }
        else{
            ans.pop_back();
        }
    }
    if(dp[i+1][sum+r[i]]==1){
        ans.push_back(1);
        if(dfs(i+1, sum+r[i])==1){
            return dp1[i][sum]=1;
        }
        else{
            ans.pop_back();
        }
    }
    return dp1[i][sum]=0;
}

void solve(){
    cin>>n>>m;
    dp.assign(n+1, vector<int>(m+1, 0));
    dp1.assign(n+1, vector<int>(m+1, -1));
    l.resize(n);
    r.resize(n);
    for(int i=0; i<n; i++){
        cin>>l[i];
    }
    for(int i=0; i<n; i++){
        cin>>r[i];
    }
    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            if(dp[i][j]==1){
                if(j+l[i]<=m){
                    dp[i+1][j+l[i]]=1;
                }
                if(j+r[i]<=m){
                    dp[i+1][j+r[i]]=1;
                }
            }
        }
    }
    if(dp[n][m]==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
    ans.clear();
    dfs(0, 0);
    for(int i=0; i<n; i++){
        cout<<ans[i];
    }
    cout<<endl;
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
