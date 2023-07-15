#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>adj;
set<pair<int, int>> lucky;
vector<int> v_down;
vector<int> v_up;
vector<int> nodes;

bool isLucky(int x){
    while(x){
        if(x%10 != 4 && x%10 != 7){
            return false;
        }
        x /= 10;
    }
    return true;
}

int dfs(int x, int p){
    for(auto y:adj[x]){
        if(y == p) continue;
        int temp = dfs(y, x);
        nodes[x] += nodes[y];
        if(lucky.find({x, y}) != lucky.end()){
            v_down[x] += nodes[y];
        }
        else{
            v_down[x] += temp;
        }
    }
    return v_down[x];
}

void dfs1(int x, int p){
    if(p!=-1){
        if(lucky.find({x, p}) != lucky.end()){
            v_up[x] = n - nodes[x];
        }
        else{
            v_up[x] = v_up[p] + v_down[p] - v_down[x];
        }
    }
    for(auto y:adj[x]){
        if(y == p) continue;
        dfs1(y, x);
    }
    return;
}

int main(){
    cin >> n;
    adj.assign(n, vector<int>());
    for(int i=0; i<n-1; i++){
        int u, v, w; cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(isLucky(w)){
            lucky.insert({u, v});
            lucky.insert({v, u});
        }
    }
    v_down.assign(n, 0);
    v_up.assign(n, 0);
    nodes.assign(n, 1);
    dfs(0, -1);
    dfs1(0, -1);
    long long ans = 0;
    for(int i=0; i<n; i++){
        int total = v_down[i] + v_up[i];
        ans += (long long)total*(total-1);
    }
    cout << ans << endl;
    return 0;
}