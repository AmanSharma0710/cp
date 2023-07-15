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

class DSU{
    int n;
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        rep(i,0,n){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py)
            return;
        if(rank[px]>rank[py])
            parent[py] = px;
        else{
            parent[px] = py;
            if(rank[px]==rank[py])
                rank[py]++;
        }
    }
};

struct Edge{
    int u,v,w;
    Edge(int u, int v, int w):u(u),v(v),w(w){}
};

vector<Edge> edges;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    edges.clear();
    DSU dsu(n);
    rep(i,0,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(dsu.find(u)!=dsu.find(v)){
            edges.push_back(Edge(u,v,i));
            dsu.merge(u,v);
        }
    }
    
    for(int qq=0;qq<q;qq++){
        int l, r;
        cin >> l >> r;
        l--; r--;

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
