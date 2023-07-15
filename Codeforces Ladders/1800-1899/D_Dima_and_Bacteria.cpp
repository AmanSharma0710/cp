#include<bits/stdc++.h>
using namespace std;
#define int long long int

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
        }
    }
};

signed main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> cnt(k);
    vector<int> a(n+1);
    vector<int> first(k+1);
    DSU dsu(n+1);
    for(auto &i: cnt) cin>>i;
    int curr = 1;
    for(int i=0; i<k; i++){
        first[i+1] = curr;
        for(int j=0; j<cnt[i]; j++){
            a[curr++] = i+1;
        }
    }
    vector<vector<int>> adj(k+1, vector<int>(k+1, INT_MAX));
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        if(w==0) dsu.merge(u, v);
        u = a[u];
        v = a[v];
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }
    for(int i=1; i<=n; i++){
        if(dsu.find(i)!=dsu.find(first[a[i]])){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(int i=1; i<=k; i++) adj[i][i] = 0;
    for(int l=1; l<=k; l++){
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                adj[i][j] = min(adj[i][j], adj[i][l]+adj[l][j]);
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            if(adj[i][j]==INT_MAX) adj[i][j] = -1;
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}