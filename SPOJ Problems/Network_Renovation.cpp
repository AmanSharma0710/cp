#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> leafs;
void dfs(int x, int p){
    if(adj[x].size()==1){
        leafs.push_back(x);
    }
    for(int y: adj[x]){
        if(y!=p){
            dfs(y, x);
        }
    }
}

int main(){
    cin>>n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    int ans=(leafs.size()+1)/2;
    cout<<ans<<endl;
    for(int i=0; i<leafs.size()/2; i++){
        cout<<leafs[i]+1<<" "<<leafs[i+leafs.size()/2]+1<<endl;
    }
    if(leafs.size()%2==1){
        cout<<leafs[0]+1<<" "<<leafs[leafs.size()-1]+1<<endl;
    }
    return 0;
}