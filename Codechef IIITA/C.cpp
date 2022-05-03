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



vector<vector<int>> children;
vector<int> parent;
vector<int> current;
vector<int> upto;
vector<int> ans;
vector<int> down;

int fill(int x){
    int gcd_current = current[x];
    for(int i=0; i<children[x].size(); i++){
        int child = children[x][i];
        int gcd_child = fill(child);
        gcd_current = gcd(gcd_current, gcd_child);
    }
    upto[x] = gcd_current;
    return gcd_current;
}

void downfill(int x){
    int n = children[x].size();
        for(int i=0; i<n; i++){
            int child = children[x][i];
            down[child] = gcd(down[x], current[x]);
            for(int j=0; j<n; j++){
                if(i!=j){
                    down[child] = gcd(down[child], upto[children[x][j]]);
                }
            }
        }
        for(int i=0; i<n; i++){
            downfill(children[x][i]);
        }
        return;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(0));
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    children.assign(n, vector<int>(0));
    parent.assign(n, -1);
    current.resize(n);
    upto.resize(n);
    ans.resize(n);
    down.resize(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        current[i] = x;
        upto[i] = x;
    }
    parent[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int v = adj[i][j];
            if(parent[v]==-1){
                parent[v]=i;
                children[i].push_back(v);
            }
        }
    }
    fill(0);
    down[0] = 0;
    downfill(0);
    ans[0]=0;
    for(int i=0; i<children[0].size(); i++){
        ans[0]+=upto[children[0][i]];
    }
    
    for(int i=1; i<n; i++){
        ans[i]=0;
        for(int j=0; j<children[i].size(); j++){
            ans[i]+=upto[children[i][j]];
        }
        ans[i] += down[i];
    }
    for(int i=0; i<n; i++){
        cout<<upto[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<down[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<< *max_element(ans.begin(), ans.end())<<"\n";
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
