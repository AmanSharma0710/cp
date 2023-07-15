#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int



void solve(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    int start = strtoll(s.c_str(), NULL, 2);
    int nodes = (1<<n);
    vector<vector<int>> adj(nodes, vector<int>(nodes, 10000000));
    for(int i=0; i<m; i++){
        int d;
        cin>>d;
        string s1, s2;
        cin>>s1>>s2;
        int u = strtoll(s1.c_str(), NULL, 2);
        int v = strtoll(s2.c_str(), NULL, 2);
        for(int j=0; j<nodes; j++){
            int to = j&(~u);
            to = to|v;
            adj[j][to] = min(adj[j][to], d);
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(nodes, 10000000);
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d>dist[u]) continue;
        for(int i=0; i<nodes; i++){
            if(adj[u][i]==10000000) continue;
            if(dist[i]>dist[u]+adj[u][i]){
                dist[i] = dist[u]+adj[u][i];
                pq.push({dist[i], i});
            }
        }
    }
    if(dist[0]==10000000) cout<<-1<<endl;
    else cout<<dist[0]<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
