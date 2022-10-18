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



void solve(){
    int n, m;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    cin>>m;
    vector<int> b(m);
    rep(i,0,m) cin>>b[i];
    int k;
    cin>>k;
    vector<int> prea(n+1, 0), posta(n+1, 0), preb(m+1, 0), postb(m+1, 0);
    for(int i=1; i<=n; i++){
        prea[i] = prea[i-1] + a[i-1];
    }
    for(int i=1; i<=m; i++){
        preb[i] = preb[i-1] + b[i-1];
    }
    for(int i=n-1; i>=0; i--){
        posta[i] = posta[i+1] + a[i];
    }
    for(int i=m-1; i>=0; i--){
        postb[i] = postb[i+1] + b[i];
    }
    int ans = 0;
    for(int k1=0; k1<=k; k1++){
        int k2 = k - k1;
        if(k1>n || k2>m) continue;
        int ans1 = 0;
        for(int i=0; i<=k1; i++){
            ans1 = max(ans1, prea[i] + posta[n - (k1-i)]);
        }
        int ans2 = 0;
        for(int i=0; i<=k2; i++){
            ans2 = max(ans2, preb[i] + postb[m - (k2-i)]);
        }
        ans = max(ans, ans1 + ans2);
    }
    cout<<ans<<endl;
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
