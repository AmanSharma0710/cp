#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int> dp;

int dfs(int x){
    if(dp[x]!=-1) return dp[x];
    if(adj[x].size()==0) return dp[x] = 0;
    int len = 0;
    for(auto it: adj[x]){
        len = max(len, dfs(it));
    }
    return dp[x] = len+1;
}

int main(){
    int n, m;
    cin>>n>>m;
    adj.assign(n, vector<int>());
    dp.assign(n, -1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dfs(i));
    }
    cout<<ans<<endl;
    return 0;
}