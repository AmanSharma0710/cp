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

vector<vector<int>>adj;
vector<int> a, b;
int ans;

void dfs(int x, int parent, bool color, int new_color){
    cout<<x<<" "<<parent<<" "<<color<<" "<<new_color<<endl;
    if(color){
        a[x] = new_color;
    }
    if(a[x]!=b[x]){
        ans++;
        color = true;
        new_color = b[x];
    }
    for(int i=0; i<adj[x].size(); i++){
        int y = adj[x][i];
        if(y==parent) continue;
        dfs(y, x, color, new_color);
    }
}

void solve(){
    int n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    adj.assign(n,vi());
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    ans=0;
    dfs(0, -1, 0, 0);
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
