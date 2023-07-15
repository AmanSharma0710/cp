#include<bits/stdc++.h>
using namespace std;

#define int long long

int ans = 0;
int n;
vector<int> v;
vector<vector<int>> adj;

int dfs(int x, int p){
    map<int, int> m;
    for(auto it:adj[x]){
        if(it==p) continue;
        m[dfs(it, x)]++;
    }
    int total = 0, mx = 0, val = 0;
    if(m.size()){
        for(auto it: m){
            // cout<<it.first<<" "<<it.second<<endl;
            total += it.second;
            mx = max(mx, it.second);
            val = it.first;
        }
        // cout<<total<<" "<<mx<<endl;
        ans+= total - mx;
    }
    // cout<<x<<":"<<(val^v[x])<<endl;
    return val^v[x];
}

signed main(){
    cin>>n;
    v.assign(n, 0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    adj.assign(n, vector<int>(0));
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(dfs(0, -1)!=0) ans++;
    cout<<ans<<endl;
}