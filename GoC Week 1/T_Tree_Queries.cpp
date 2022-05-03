#include<bits/stdc++.h>
using namespace std;
#define int long long int


vector<vector<int>> adj;
vector<int> height;
vector<int> parent;

void solve(){
    int n, Q;
    cin >> n >> Q;
    adj.assign(n, vector<int>());
    height.assign(n, 0);
    parent.assign(n, -1);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cureent_height = 0;
    queue<int> q;
    vector<int> visited(n, 0);
    q.push(0);
    q.push(-1);
    visited[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == -1){
            cureent_height++;
            if(!q.empty()) q.push(-1);
            continue;
        }
        height[u] = cureent_height;
        for(int v : adj[u]){
            if(visited[v] == 0){
                parent[v] = u;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    for(int _ = 0; _ < Q; _++){
        int x;
        cin >> x;
        vector<pair<int, int>> vertices;
        for(int i=0; i<x; i++){
            int v;
            cin >> v;
            v--;
            vertices.push_back({height[v], v});
        }
        bool ans = true;
        sort(vertices.begin(), vertices.end());
        set<int> path;
        int node = vertices[x-1].second;
        while(node != -1){
            path.insert(node);
            node = parent[node];
        }
        for(int i=0; i<x; i++){
            if((path.find(vertices[i].second) == path.end()) && (path.find(parent[vertices[i].second]) == path.end())){
                ans = false;
                break;
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }


    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
