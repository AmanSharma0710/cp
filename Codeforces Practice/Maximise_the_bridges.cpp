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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vi> adj(n, vector<int>(n, 0));
    m -= n-1;
    for(int i=1; i<n; i++){
        adj[i][0] = 1;
        adj[0][i] = 1;
    }    
    for(int i=1; i<n; i++){
        for(int j=2; j<i+2; j++){
            if(!m){
                break;
            }
            adj[i][j] = 1;
            adj[j][i] = 1;
            m--;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(adj[i][j]){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
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
