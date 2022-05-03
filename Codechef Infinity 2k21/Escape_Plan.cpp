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
    int n;
    cin>>n;
    if(n==1){
        int x;
        cin>>x;
        cout<<x<<endl;
        return;
    }
    vector<vector<int>>adj(n, vector<int>(0));
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> cost(n);
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }
    int ans=0;
    for(int i=1; i<n; i++){
        if(adj[i].size()==1){
            ans+=cost[i];
        }
    }
    cout<<ans<<endl;
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
