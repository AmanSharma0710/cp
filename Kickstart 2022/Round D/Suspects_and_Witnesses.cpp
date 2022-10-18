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

vector<int> dp;
vector<vector<int>> adj;

bool visitor(int x, map<int, bool> &vis, int &k){
    if(k==0) return 1;
    if(vis[x]) return 0;
    vis[x]=1;
    k--;
    for(int i=(int)adj[x].size()-1;i>=0;i--){
        if(visitor(adj[x][i],vis,k)) return 1;
    }
    if(k==0) return 1;
    return 0;
}


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    dp.assign(n, 0);
    adj.assign(n, vector<int>());
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        y--;
        x--;
        adj[y].push_back(x);
    }
    for(int i=n-1; i>=0; i--){
        for(auto j: adj[i]){
            if(dp[j]){
                dp[i] = 1;
            }
        }
        if(!dp[i]){
            map<int, bool> vis;
            int k2 = k+1;
            if(visitor(i, vis, k2)){
                dp[i] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += dp[i];
    }
    cout << ans << endl;
    dp.clear();
    adj.clear();
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1, tc=1;
    cin>>t;
    while (t--){
        cout<<"Case #"<<tc++<<": ";
        solve();       
    }
    return 0;
}
