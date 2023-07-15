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

//import policy based data structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;     
//for multiset use less_equal<int> instead of less<int>
//for map use Mapped as second argument

int n;
vector<int> rating;
vector<vector<int>> adj;
vector<int> ans;

pbds dfs(int u){
    pbds s;
    for(auto v:adj[u]){
        pbds temp = dfs(v);
        if(temp.size()>s.size()){
            s.swap(temp);
        }
        for(auto x:temp){
            s.insert(x);
        }
    }
    int cnt = s.size() - s.order_of_key(rating[u]);
    ans[u] = cnt;
    s.insert(rating[u]);
    return s;
}

void solve(){
    //change input stream to promote.in and output stream to promote.out
    FILE *fp1 = freopen("promote.in", "r", stdin);
    cin>>n;
    rating.resize(n);
    adj.resize(n);
    rep(i,0,n){
        cin>>rating[i];
    }
    rep(i,0,n-1){
        int u;
        cin>>u;
        u--;
        adj[u].push_back(i+1);
    }
    ans.assign(n, 0);
    dfs(0);
    FILE *fp = freopen("promote.out", "w", stdout);
    rep(i,0,n){
        cout<<ans[i]<<"\n";
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t=1;
    //cin>>t;
    while (t--){
        solve();       
    }
    return 0;
}
