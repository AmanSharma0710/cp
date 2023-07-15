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

int n;
vector<int> color;
vector<vector<int>> adj;
vector<int> ans;
vector<int> c;

map<int, int> dfs(int x, int p){
    map<int, int> cnt;
    cnt[color[x]] = 1;
    ans[x] = color[x];
    c[x] = 1;
    for(auto y : adj[x]){
        if(y == p) continue;
        map<int, int> cur = dfs(y, x);
        if(cur.size() > cnt.size()){
            swap(cur, cnt);
            c[x] = c[y];
            ans[x] = ans[y];
        }
        for(auto p : cur){
            cnt[p.first] += p.second;
            if(cnt[p.first] > c[x]){
                c[x] = cnt[p.first];
                ans[x] = p.first;
            }
            else if(cnt[p.first] == c[x]){
                ans[x] += p.first;
            }
        }
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    color.resize(n);
    rep(i,0,n) cin>>color[i];
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans.assign(n,0);
    c.assign(n,0);
    dfs(0,-1);
    rep(i,0,n) cout<<ans[i]<<" ";
    return 0;
}
