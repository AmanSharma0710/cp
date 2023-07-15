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

int n, q;
vector<char> v;
vector<vector<int>>cnt;
vector<vector<int>>adj;

vector<int> dfs(int x, int parent){
    cnt[x][v[x]-'a']++;
    for(auto i: adj[x]){
        if(i==parent) continue;
        vector<int>temp = dfs(i, x);
        for(int j=0; j<26; j++) cnt[x][j]+=temp[j];
    }
    return cnt[x];
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    v.resize(n);
    cnt.assign(n, vector<int>(26, 0));
    adj.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    while(q--){
        int x;
        cin>>x;
        x--;
        string s;
        cin>>s;
        vector<int>temp(26, 0);
        for(auto i: s) temp[i-'a']++;
        int ans = 0;
        for(int i=0; i<26; i++) ans+=max(0LL, temp[i]-cnt[x][i]);
        cout<<ans<<endl;
    }
    return 0;
}
