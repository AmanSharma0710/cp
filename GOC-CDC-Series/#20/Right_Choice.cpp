#include<bits/stdc++.h>
using namespace std;
#define int long long int


signed main(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    vector<vector<pair<int, int>>> v(mx+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v[a[i][j]].push_back({i, j});
        }
    }
    vector<vector<int>> multiples(mx+1, vector<int>(0));
    for(int i=1; i<=mx; i++){
        for(int j=i; j<=mx; j+=i){
            if(v[j].size()>0){
                multiples[i].push_back(j);
            }
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        x1--; y1--; x2--; y2--;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<bool> vis1(mx+1, false);
        int dist = 0;
        bool ans = false;
        q.push({x2, y2});
        vis[x2][y2] = true;
        q.push({-1, -1});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.first==-1){
                dist++;
                if(dist==5) break;
                if(q.empty()) break;
                q.push({-1, -1});
                continue;
            }
            if(p.first==x1 && p.second==y1){
                ans = true;
                break;
            }
            //push neighbours into queue
            if(p.first>0 && !vis[p.first-1][p.second]){
                vis[p.first-1][p.second] = true;
                q.push({p.first-1, p.second});
            }
            if(p.first<n-1 && !vis[p.first+1][p.second]){
                vis[p.first+1][p.second] = true;
                q.push({p.first+1, p.second});
            }
            if(p.second>0 && !vis[p.first][p.second-1]){
                vis[p.first][p.second-1] = true;
                q.push({p.first, p.second-1});
            }
            if(p.second<m-1 && !vis[p.first][p.second+1]){
                vis[p.first][p.second+1] = true;
                q.push({p.first, p.second+1});
            }
            //if multiple of a[p.first][p.second] is not visited, push it into queue
            if(!vis1[a[p.first][p.second]]){
                vis1[a[p.first][p.second]] = true;
                for(auto i: multiples[a[p.first][p.second]]){
                    for(auto j: v[i]){
                        if(!vis[j.first][j.second]){
                            vis[j.first][j.second] = true;
                            q.push({j.first, j.second});
                        }
                    }
                }
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}