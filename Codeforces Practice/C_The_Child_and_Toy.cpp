#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<pii> v(n);
    rep(i, 0, n){
        cin>>v[i].first;
        v[i].second = i;
    }
    int ans = 0;
    vector<vector<int>>adj(n);
    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sort(v.begin(), v.end());
    vector<bool> vis(n, false);
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<adj[v[i].second].size(); j++){
            if(!vis[adj[v[i].second][j]]){
                ans += v[adj[v[i].second][j]].first;
            }
        }
        vis[v[i].second] = true;
    }
    cout<<ans<<endl;
    return 0;
}
