#include<bits/stdc++.h>
using namespace std;
#define int long long int



signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>adj;
    adj.assign(n, vector<int>(0));
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<set<int>> q;
    set<int> s;
    s.insert(0);
    q.push(s);
    s.clear();
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        int x; cin>>x; x--;
        if(visited[x]){
            cout<<"No"<<endl;
            return 0;
        }
        else{
            visited[x]=true;
        }
        if((q.front()).find(x)!=(q.front().end())){
            q.front().erase(x);
            if(q.front().empty()){
                q.pop();
            }
            q.push(s);
            for(int j=0; j<adj[x].size(); j++){
                if(adj[x][j]==parent[x]){
                    continue;
                }
                (q.back()).insert(adj[x][j]);
                parent[adj[x][j]]=x;
            }
            continue;
        }
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}
