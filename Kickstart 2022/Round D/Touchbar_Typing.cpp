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
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    int m;
    cin>>m;
    vector<int> b(m);
    rep(i,0,m) cin>>b[i];
    vector<int> s;
    s.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(s.back()!=a[i]){
            s.push_back(a[i]);
        }
    }
    n = s.size();
    vector<int> dp(m, INT_MAX), dp1(m, INT_MAX);
    for(int i=0; i<m; i++){
        if(b[i]==s.back()){
            dp[i] = 0;
        }
    }
    for(int i=n-2; i>=0; i--){
        //for every character, we find the minimum distance to the nearest character before that
        int dist = INT_MAX, cost = INT_MAX;
        for(int j=0; j<m; j++){
            if(dp[j]<INT_MAX){
                dist=0;
                cost = dp[j];
            }
            else{
                dist++;
            }
            if(b[j]==s[i]){
                dp1[j] = dist + cost;
            }
        }
        dist = INT_MAX, cost = INT_MAX;
        for(int j=m-1; j>=0; j--){
            if(dp[j]<INT_MAX){
                dist=0;
                cost = dp[j];
            }
            else{
                dist++;
            }
            if(b[j]==s[i]){
                dp1[j] = min(dp1[j], dist + cost);
            }
        }
        for(int j=0; j<m; j++){
            dp[j] = dp1[j];
            dp1[j] = INT_MAX;
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<m; i++){
        ans = min(ans, dp[i]);
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
