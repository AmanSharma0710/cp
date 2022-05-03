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

vector<vector<int>>adj;
vector<int> dp;

int dfs(int x){
    if(dp[x]==-1){
        if(adj[x].size()==0){
            dp[x]=0;
        }
        else{
            for(auto j=adj[x].begin(); j!=adj[x].end(); j++){
                dp[x] = max(dp[x], 1 + dfs(*j));
            }
        }
    }
    return dp[x];
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    adj.assign(n, vector<int>(0));
    dp.assign(n, -1);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(dfs(i), ans);
    }
    cout<<ans<<endl;
    return 0;
}
