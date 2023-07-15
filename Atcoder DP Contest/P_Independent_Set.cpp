#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<int>>adj;
vector<vector<int>>dp;

int dfs(int x, int color, int parent){
    if(dp[x][color]!=-1) return dp[x][color];
    long long ways = 1;
    if(color==0){
        for(auto it:adj[x]){
            if(it==parent) continue;
            ways *= (dfs(it, 0, x) + dfs(it, 1, x))%MOD;
            ways %=MOD;
        }
    }
    else{
        for(auto it:adj[x]){
            if(it==parent) continue;
            ways *= dfs(it, 0, x);
            ways %=MOD;
        }
    }
    return dp[x][color] = ways;
}

int main(){
    cin>>n;
    adj.assign(n, vector<int>());
    dp.assign(n, vector<int>(2, -1));
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<(dfs(0, 0, -1) + dfs(0, 1, -1))%MOD<<endl;
    return 0;
}