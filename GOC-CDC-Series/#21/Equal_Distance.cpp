#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>>adj;
int ans = 0;

int dfs(int x, int p){
    set<int>st;
    for(auto it: adj[x]){
        if(it.first==p) continue;
        int len = dfs(it.first, x);
        st.insert(it.second+len);
    }
    if(st.size()==0) return 0;
    ans += st.size()-1;
    return *st.rbegin();
}

int main(){
    cin>>n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(0, -1);
    cout<<ans<<endl;
    return 0;
}