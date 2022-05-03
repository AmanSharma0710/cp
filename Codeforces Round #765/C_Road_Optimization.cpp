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

vector<int> position;
vector<int> speed;
vector<vector<int>> adj;
int k;

vector<vector<int>> dp;

int dfs(int x, int cost){
    assert(cost>=0);
    if(cost > k) return INT_MAX;
    if(x == position.size()-1) return 0;
    if(dp[x][cost] != -1) return dp[x][cost];
    int ans = INT_MAX;
    for(int next=x+1; next<adj[x].size() && next<=x+k+1; next++){
        int next_cost = cost + abs(x - next)-1;
        ans = min(ans, adj[x][next] + dfs(next, next_cost));
    }
    return dp[x][cost] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l;
    cin>>n>>l>>k;
    rep(i,0,n){
        int x;
        cin>>x;
        position.push_back(x);
    }
    position.push_back(l);
    rep(i,0,n){
        int x;
        cin>>x;
        speed.push_back(x);
    }
    speed.push_back(0);
    adj.assign(n+1, vector<int>(n+1, INT_MAX));
    for(int i=0; i<=n; i++){
        for(int j=i+1; j<=i+k+1 && j<=n; j++){
            adj[i][j] = speed[i]*(position[j]-position[i]);
        }
    }
    dp.assign(n+1, vector<int>(k+1, -1));
    cout<<dfs(0, 0)<<endl;
    return 0;
}
