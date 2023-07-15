#include<bits/stdc++.h>
using namespace std;

// #define int long long

int n, m;
vector<vector<int>> adj;
vector<int>dis;

class LCA{
public:
    int N;
    static const int D = 18;    //around 2e5
    vector<vector<int>> table;
    vector<vector<int>> tree;
 
    vector<int> depth;
 
    LCA(vector<vector<int>> &tree)
    {
        N = tree.size();
        this->tree = tree;
        depth.assign(N, 0);
        table.assign(D, vector<int>(N, -1));
        dfs(0, -1);
        for (int i = 1; i < D; i++)
        {
            for (int u = 0; u < N; u++)
            {
                if (table[i - 1][u] >= 0)
                    table[i][u] = table[i - 1][table[i - 1][u]];
                else
                    table[i][u] = -1;
            }
        }
    }
 
    void dfs(int u, int p)
    {
        table[0][u] = p;
        for (int v : tree[u])
        {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
 
    int up(int u, int dist)
    {
        for (int i = D - 1; i >= 0; i--)
        {
            if ((dist & (1 << i)) > 0)
            {
                u = table[i][u];
                if (u == -1)
                    return -1;
            }
        }
        return u;
    }
 
    int lca(int u, int v)
    {
        if (depth[u] < depth[v])
        {
            return lca(v, u);
        }
 
        int diff = depth[u] - depth[v];
        u = up(u, diff);
        if (u == v)
            return u;
 
        for (int i = D - 1; i >= 0; i--)
        {
            if (table[i][u] != table[i][v])
            {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
 
    int distance(int u, int v)
    {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};


void updateDis(){
    queue<pair<int, int>>q;
    vector<bool>vis(n, false);
    for(int i=0; i<n; i++){
        if(dis[i]==0){
            q.push({i, 0});
            vis[i] = true;
        } 
    }
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int u = x.first;
        int d = x.second;
        for(auto y: adj[x.first]){
            if(!vis[y]){
                vis[y] = true;
                dis[y] = x.second+1;
                q.push({y, x.second+1});
            }
        }
    }
}

signed main(){
    cin>>n>>m;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca(adj);
    dis.assign(n, 1e8);
    dis[0] = 0;
    updateDis();
    int blockSz = sqrt(m);
    vector<int> toUpdate;
    for(int i=0; i<m; i++){
        if(i%blockSz==0){
            for(auto x: toUpdate){
                dis[x] = 0;
            }
            toUpdate.clear();
            updateDis();
        }
        int type, vertex;
        cin>>type>>vertex;
        vertex--;
        if(type==2){
            int ans = dis[vertex];
            for(auto x: toUpdate){
                ans = min(ans, lca.distance(x, vertex));
            }
            cout<<ans<<endl;
        }
        else{
            if(dis[vertex]!=0) toUpdate.push_back(vertex);
        }
    }
    return 0;
}