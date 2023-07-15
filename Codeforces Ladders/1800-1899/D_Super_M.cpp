#include<bits/stdc++.h>
using namespace std;

int n, m, root;
vector<vector<int>> adj;
vector<int>attacked;
int cnt=0;

bool dfs(int x, int p){
    set<int> remove;
    bool flag = false;
    for(auto y:adj[x]){
        if(y==p) continue;
        bool temp = dfs(y, x);
        if(!temp){
            remove.insert(y);
        }
        flag |= temp;
    }
    flag |= binary_search(attacked.begin(), attacked.end(), x);
    if(flag){
        vector<int> temp;
        for(auto y: adj[x]){
            if(remove.find(y)==remove.end()){
                temp.push_back(y);
            }
        }
        swap(adj[x], temp);
    }
    if(flag && x!=root) cnt+=2;
    return flag;
}

int bfs(int x, int &max_dist){
    max_dist = 0;
    //returns the farthest node from x with the minimum index
    int temp=INT_MAX, dist=0;
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(x);
    vis[x] = true;
    q.push(-1);
    while(!q.empty()){
        x = q.front();
        q.pop();
        if(x==-1){
            dist++;
            if(!q.empty()) q.push(-1);
            continue;
        }
        if(dist>max_dist){
            max_dist = dist;
            temp = x;
        }
        else if(dist==max_dist){
            temp = min(temp, x);
        }
        for(auto y: adj[x]){
            if(!vis[y]){
                vis[y] = true;
                q.push(y);
            }
        }
    }
    return temp;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto &i: adj){
        sort(i.begin(), i.end());
    }
    attacked.resize(m);
    for(auto &i: attacked){
        cin>>i;
        i--;
    }
    sort(attacked.begin(), attacked.end());
    root = attacked[0];
    dfs(root, -1);
    int max_dist = 0;
    int x = bfs(root, max_dist);
    int y = bfs(x, max_dist);
    cout<<min(x, y)+1<<endl;
    if(cnt==0) cout<<0<<endl;
    else cout<<cnt-max_dist<<endl;
    return 0;
}
