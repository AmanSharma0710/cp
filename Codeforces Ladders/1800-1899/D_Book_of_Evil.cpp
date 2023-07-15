#include<bits/stdc++.h>
using namespace std;

int n, m, d;
vector<bool> affected;
vector<vector<int>>adj;
vector<int> dis_down;
vector<int> dis_up;
vector<pair<int, int>> max_down;

int dfs(int x, int parent){
    vector<int> temp;
    if(affected[x]){
        dis_down[x] = max(dis_down[x], 0);
        temp.push_back(0);
    }
    for(auto u: adj[x]){
        if(u != parent){
            int val = dfs(u, x) + 1;
            dis_down[x] = max(dis_down[x], val);
            temp.push_back(val);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());
    if(temp.size() >= 2){
        max_down[x] = {temp[0], temp[1]};
    }
    else if(temp.size() == 1){
        max_down[x] = {temp[0], INT_MIN};
    }
    else{
        max_down[x] = {INT_MIN, INT_MIN};
    }
    return dis_down[x];
}

void dfs1(int x, int parent){
    if(affected[x]){
        dis_up[x] = max(dis_up[x], 0);
    }
    if(parent != -1){
        if(max_down[parent].first == dis_down[x] + 1){
            dis_up[x] = max(dis_up[x], max_down[parent].second + 1);
        }
        else{
            dis_up[x] = max(dis_up[x], max_down[parent].first + 1);
        }
        dis_up[x] = max(dis_up[x], dis_up[parent] + 1);
    }
    for(auto u: adj[x]){
        if(u != parent){
            dfs1(u, x);
        }
    }
    return;
}

int main(){
    cin >> n >> m >> d;
    affected.assign(n, false);
    adj.assign(n, vector<int>());
    for(int i=0; i<m; i++){
        int x; cin>>x;
        x--;
        affected[x] = true;
    }
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dis_down.assign(n, INT_MIN);
    dis_up.assign(n, INT_MIN);
    max_down.assign(n, {INT_MIN, INT_MIN});
    dfs(0, -1);
    dfs1(0, -1);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(dis_down[i] <= d && dis_up[i] <= d){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}