#include<bits/stdc++.h>
using namespace std;

unordered_set<int> s;

#define int long long int

int n;
bool ans = true;
vector<vector<int>> adj;

int dfs(int x, int parent){
    int len = -1;
    for(auto y: adj[x]){
        if(y==parent) continue;
        int l = dfs(y, x);
        if(len==-1) len = l%2;
        else if(len!=l%2) ans = false;
    }
    if(len==-1) len = 0;
    return len + 1;
}

int dfs1(int x, int parent, int root){
    int sum = 0;
    bool one = false;
    for(auto y: adj[x]){
        if(y==parent) continue;
        int temp = dfs1(y, x, root);
        if(temp!=1) sum += temp;
        else one = true;
    }
    if(one && parent==root){
        one = false;
    }
    if(one) sum++;
    if(parent==-1) return sum;
    return sum + 1;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 0;
    for(int i=0; i<n; i++){
        if(adj[i].size()==1){
            root = i;
            break;
        }
    }
    if(dfs(root, -1)%2==0) ans = false;
    if(ans) cout<<1<<" ";
    else cout<<3<<" ";
    cout<<dfs1(root, -1, root)<<endl;
    return 0;
}