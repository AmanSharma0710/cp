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

vector<bool> hasCat;
vector<bool> visited;
vector<vector<int>> adj;
int ans;
void dfs(int x, int cats, int m){
    visited[x] = true;
    if(cats>m){
        return;
    }
    bool leaf=true;
    for(int i=0; i<adj[x].size(); i++){
        int y = adj[x][i];
        if(!visited[y]){
            leaf = false;
            if(hasCat[y]){
                dfs(y, cats+1, m);
            }
            else{
                dfs(y, 0, m);
            }
        }
    }
    if(leaf){
        ans++;
    }
    return;
}
void solve(){ 
    int n, m;
    cin>>n>>m;
    hasCat.resize(n+1);
    visited.resize(n+1);
    adj.resize(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(x==1) hasCat[i]=true;
    }
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=0;
    if(hasCat[1]){
        dfs(1, 1, m);
    }
    else{
        dfs(1,0, m);
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
