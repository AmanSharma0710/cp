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

int n, m;
vector<vector<int>> shots;
vector<vector<int>> vis;
int ans;

void solve(){
    cin>>n>>m;
    vis.resize(n+1, vector<int>(m+1, INT_MAX));
    shots.clear();
    ans = INT_MAX;
    int r;
    cin>>r;
    for(int i=0; i<r; i++){
        int x, y, z;
        cin>>x>>y>>z;
        shots.push_back({x,y,z});
    }
    sort(shots.begin(), shots.end());
    int start = 1;
    vis[0][0] = 0;
    for(int cur_shot=0; cur_shot<r; cur_shot++){
        int steps = shots[cur_shot][0] - start;
        vector<vector<int>> temp(n+1, vector<int>(m+1, INT_MAX));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != INT_MAX){
                    for(int x = 0; x < steps; x++){
                        
                    }
                }
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