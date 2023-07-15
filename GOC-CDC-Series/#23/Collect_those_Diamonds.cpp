#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n;
vector<vector<int>> adj;

pair<int, int> dfs(int x, int p){
    pair<int, int> ans = {x, 0};
    for(auto y: adj[x]){
        if(y==p) continue;
        pair<int, int> temp = dfs(y, x);
        if(temp.second + 1 > ans.second){
            ans = {temp.first, temp.second + 1};
        }
    }
    return ans;
}

pair<int, int> dfs2(int x, int p){
    pair<int, int> ans = {1, 1};
    for(auto y: adj[x]){
        if(y==p) continue;
        pair<int, int> temp = dfs2(y, x);
        int temp2 = max(ans.second, temp.second + 1);
        temp2 = max(temp2, ans.first + temp.first);
        ans.second = temp2;
        ans.first = max(ans.first, temp.first + 1);
    }
    return ans;
}

void solve(){
    cin>>n;
    adj.assign(n, vector<int>());
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a;
    pair<int, int> temp = dfs(0, -1);
    a = temp.first;
    temp = dfs2(a, -1);
    cout<< max(temp.first, temp.second) <<endl;
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
