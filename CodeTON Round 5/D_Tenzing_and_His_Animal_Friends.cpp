#include<bits/stdc++.h>
using namespace std;
#define int long long int




signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n, 1e18);
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<pair<vector<bool>, int>>vis2;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(vis[u]==false){
            vis2.push_back({vis, w});
            vis2.back().first[u] = true;
        }
        if(u == n-1) break;
        vis[u] = true;
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(!vis[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    if(dist[n-1] == 1e18){
        cout<<"inf"<<endl;
        return 0;
    }
    cout<<dist[n-1]<<" "<<vis2.size()-1<<endl;
    for(int i=0; i<vis2.size()-1; i++){
        for(auto it: vis2[i].first){
            cout<<it;
        }
        int u = vis2[i].second;
        int v = vis2[i+1].second;
        cout<<" "<<v-u<<endl;
    }
    return 0;
}
