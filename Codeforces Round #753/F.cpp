#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){                //to sort vii by second element use sort(v.begin(), v.end(), sortbysec);
    return (a.second < b.second);
}
#define MOD 1000000007

vector<int> adj;
vector<int> dis;
vector<int> terminates;
vector<bool> current;

void dfs(int x, int distance){
    current[x] = 1;
    dis[x] = distance;
    if(current[adj[x]]){
        dis[x] = distance-dis[adj[x]]+1;
        terminates[x] = 1;
        terminates[adj[x]] = -1;
        current[x] = 0;
        return;
    }
    if(dis[adj[x]]==0){
        dis[x] = 1;
        current[x] = 0;
        return;
    }
    if(dis[adj[x]]==-1){
        dfs(adj[x], distance+1);
    }
    if(terminates[adj[x]] == 1){
        dis[x] = dis[adj[x]];
        terminates[adj[x]] = 0;
        terminates[x]++;
        current[x] = 0;
        return;
    }
    dis[x] = dis[adj[x]]+1;
    current[x] = 0;
    return;

}

void solve(){
    int n, m;
    cin>>n>>m;
    adj.assign(n*m+1, 0);
    current.assign(n*m+1, false);
    dis.assign(n*m+1, -1);
    terminates.assign(n*m+1, 0);
    dis[0] = 0;
    terminates[0] = 0;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            if(s[j]=='U'){
                if((i-1)*m+j+1 > 0)
                    adj[i*m+j+1]=((i-1)*m+j+1);
            }
            if(s[j]=='D'){
                if((i+1)*m+j+1 <= m*n)
                    adj[i*m+j+1]=((i+1)*m+j+1);
            }
            if(s[j]=='L'){
                if(j > 0)
                    adj[i*m+j+1]=(i*m+j);
            }
            if(s[j]=='R'){
                if(j < m-1)
                    adj[i*m+j+1]=(i*m+j+2);
            }
        }
    }    
    for(int i=1; i<=n*m; i++){
        if(dis[i] == -1){
            dfs(i, 1);
        }
    }
    int index = max_element(dis.begin(), dis.end()) - dis.begin() - 1;
    cout<<(index/m+1)<<" "<<(index%m+1)<<" "<< *max_element(dis.begin(), dis.end())<<endl;
    adj.resize(0);
    current.resize(0);
    dis.resize(0);
    terminates.resize(0);
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



