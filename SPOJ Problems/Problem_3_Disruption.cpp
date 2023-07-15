#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>>adj, added;
vector<int>edges;
map<pair<int, int>, int>mp;

set<pair<int, int>> dfs(int x, int p){
    set<pair<int, int>> s;
    for(auto it:added[x]) s.insert({edges[it], it});
    for(auto y:adj[x]){
        if(y==p) continue;
        set<pair<int, int>> temp = dfs(y, x);
        if(temp.size()>s.size()) s.swap(temp);
        for(auto it: temp){
            if(s.find(it)!=s.end()){
                s.erase(it);
            }
            else{
                s.insert(it);
            }
        }
    }
    if(p==-1) return s;
    if(s.size()){
        mp[{x, p}] = mp[{p, x}] = (*s.begin()).first;
    }
    else{
        mp[{x, p}] = mp[{p, x}] = -1;
    }
    return s;
}

int main(){
    FILE* fp = freopen("disrupt.in", "r", stdin);
    cin>>n>>m;
    adj.assign(n, vector<int>());
    added.assign(n, vector<int>());
    vector<pair<int, int>>e(n-1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e[i].first = u;
        e[i].second = v;
    }
    edges.resize(m);
    for(int i=0; i<m; i++){
        int u, v, p;
        cin>>u>>v>>p;
        u--;
        v--;
        added[u].push_back(i);
        added[v].push_back(i);
        edges[i] = p;
    }
    dfs(0, -1);
    FILE* fp1 = freopen("disrupt.out", "w", stdout);
    for(int i=0; i<n-1; i++){
        cout<<mp[e[i]]<<endl;
    }
    return 0;
}