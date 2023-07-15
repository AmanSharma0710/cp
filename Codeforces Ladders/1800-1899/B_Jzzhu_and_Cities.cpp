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
int power(int x, int y, int p){
    int res = 1; 
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;
    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);
        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }
    return result;
}

bool isPrime(unsigned n) {
    if (n < 2)
        return false;
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);
        if (x <= 1 || x == n - 1)
            continue;
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
        if (x != n - 1)
            return false;
    }
    return true;
}


int n,m,k;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<int> dist;
void solve(){
    cin>>n>>m>>k;
    adj.resize(n+1);
    vis.assign(n+1, false);
    dist.assign(n+1, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    rep(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vis[1] = true;
    dist[1] = 0;
    for(int i=0; i<k; i++){
        int s, y;
        cin>>s>>y;
        pq.push({y, 1, s});
    }
    for(auto it: adj[1]){
        pq.push({it.second, 0, it.first});
    }
    int ans = 0;
    while(!pq.empty()){
        int cost = pq.top()[0];
        int node = pq.top()[2];
        int rail = pq.top()[1];
        if(!vis[node]){
            vis[node] = true;
            dist[node] = cost;
            for(auto it: adj[node]){
                if(!vis[it.first]){
                    pq.push({cost+it.second, 0, it.first});
                }
            }
        }
        else if(rail) ans++;
        pq.pop();
    }
    cout<<ans<<"\n";
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
