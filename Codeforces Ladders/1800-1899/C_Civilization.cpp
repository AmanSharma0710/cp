#include<bits/stdc++.h>
using namespace std;

int n, m, q;
vector<vector<int>> adj;
vector<int> vis;
map<int, int> dist;
vector<int> temp;

class DSU{
    public:
    int n;
    vector<int> parent, rank;
    DSU(int n): n(n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    ~DSU(){
        parent.clear();
        rank.clear();
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
            }
            else if(rank[s1]>rank[s2]){
                parent[s2] = s1;
            }
            else{
                parent[s1] = s2;
                rank[s2]++;
            }
            int new_dist = max(dist[s1], dist[s2]);
            new_dist = max(new_dist, (dist[s1]+1)/2 + (dist[s2]+1)/2 + 1);
            dist[find(x)] = new_dist;
        }
    }
};

DSU *dsu;

pair<int, int> dfs(int x, int p){
    vis[x] = 1;
    temp.push_back(x);
    pair<int, int> ans = {x, 0};
    for(auto y:adj[x]){
        if(y==p) continue;
        pair<int, int> temp1 = dfs(y, x);
        if(temp1.second>ans.second){
            ans = temp1;
        }
    }
    ans.second++;
    return ans;
}

void fill(int x){
    temp.clear();
    pair<int, int> temp1 = dfs(x, -1);
    temp1 = dfs(temp1.first, -1);
    for(auto i: temp){
        dsu->merge(x, i);
    }
    dist[dsu->find(x)] = temp1.second-1;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>q;
    adj.resize(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.assign(n, 0);
    dsu = new DSU(n);
    for(int i=0; i<n; i++){
        if(!vis[i]) fill(i);
    }
    for(int i=0; i<q; i++){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            x--;
            cout<<dist[dsu->find(x)]<<endl;
        }
        else{
            int x, y;
            cin>>x>>y;
            x--; y--;
            dsu->merge(x, y);
        }
    }
    return 0;
}
