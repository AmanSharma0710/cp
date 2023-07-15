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
vector<vector<int>> relations(26, vector<int> (26, 0));
void dfs(int x, int parent, vector<int> &visited){
    visited[x] = 1;
    for(int i=0; i<26; i++){
        if(relations[x][i] == 1){
            if(i == parent) continue;
            dfs(i, x, visited);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        char a, b;
        cin>>a>>b;
        int x = a-'a';
        int y = b-'a';
        relations[x][y] = 1;
        relations[y][x] = 1;
    }
    for(int i=0; i<26; i++){
        vector<int> visited(26, 0);
        dfs(i, -1, visited);
        visited[i] = 0;
        for(int j=0; j<26; j++){
            if(visited[j]){
                relations[i][j] = 1;
            }
        }
    }
    vector<int> dp[26];
    for(int i=0; i<26; i++){
        dp[i].assign(n, 0);
    }
    for(int i=0; i<26; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<26; j++){
            for(int k=0; k<26; k++){
                if(relations[j][k]==0){
                    dp[j][i] = (dp[j][i] + dp[k][i-1])%MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<26; i++){
        ans = (ans + dp[i][n-1])%MOD;
    }
    cout<<ans<<endl;
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
