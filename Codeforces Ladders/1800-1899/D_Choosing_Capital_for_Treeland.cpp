#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n;
vector<vector<int>>adj;
set<pair<int, int>>dne;
vector<int>ans;
int total = 0;

void dfs(int u, int p, int edges, int dist){
    if(dne.find({u, p}) != dne.end()){
        edges++;
        total++;
    }
    for(auto v: adj[u]){
        if(v == p)
            continue;
        dfs(v, u, edges, dist+1);
    }
    ans[u] = dist-2*edges;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    adj.assign(n+1, vector<int>());
    ans.assign(n+1, 0);
    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dne.insert({a, b});
    }
    dfs(1, 0, 0, 0);
    int minn = *min_element(ans.begin()+1, ans.end());
    cout<<minn+total<<endl;
    for(int i=1; i<=n; i++){
        if(ans[i] == minn)
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
